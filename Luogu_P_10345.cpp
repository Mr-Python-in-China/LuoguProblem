#include <arpa/inet.h>
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
std::ifstream fin("./data/P10345.in", std::ifstream::binary);
#else
std::istream& fin = std::cin;
#endif

u_int8_t bitreverse(uint8_t x) {
  x = ((x & 0xaa) >> 1) | ((x & 0x55) << 1);
  x = ((x & 0xcc) >> 2) | ((x & 0x33) << 2);
  x = ((x & 0xf0) >> 4) | ((x & 0x0f) << 4);
  return x;
}

struct PackageCheckError {};

struct pcap_hdr {
  // 所有字段都是大端序
  uint32_t magic_number;   // 用于文件类型识别，始终为 0xA1B2C3D4，
  uint16_t version_major;  // 始终为 2
  uint16_t version_minor;  // 始终为 4
  int32_t thiszone;        // 始终为 0
  uint32_t sigfigs;        // 始终为 0
  uint32_t snaplen;        // 允许的最大包长度，始终为 262144
  uint32_t network;  // 数据类型，本次学习题中始终为 1 （以太网）
  pcap_hdr(std::vector<uint8_t>::const_iterator begin)
      : magic_number((begin[0] << 24) + (begin[1] << 16) + (begin[2] << 8) +
                     (begin[3] << 0)),
        version_major((begin[4] << 8) + (begin[5] << 0)),
        version_minor((begin[6] << 8) + (begin[7] << 0)),
        thiszone((begin[8] << 24) + (begin[9] << 16) + (begin[10] << 8) +
                 (begin[11] << 0)),
        sigfigs((begin[12] << 24) + (begin[13] << 16) + (begin[14] << 8) +
                (begin[15] << 0)),
        snaplen((begin[16] << 24) + (begin[17] << 16) + (begin[18] << 8) +
                (begin[19] << 0)),
        network((begin[20] << 24) + (begin[21] << 16) + (begin[22] << 8) +
                (begin[23] << 0)) {
    assert(magic_number == 0xA1B2C3D4 && version_major == 2 &&
           version_minor == 4 && thiszone == 0 && sigfigs == 0 &&
           snaplen == 262144 && network == 1);
  }
  friend std::ostream& operator<<(std::ostream& out, pcap_hdr data) {
    data.magic_number = htonl(data.magic_number),
    data.version_major = htons(data.version_major),
    data.version_minor = htons(data.version_minor),
    data.thiszone = htonl(data.thiszone), data.sigfigs = htonl(data.sigfigs),
    data.snaplen = htonl(data.snaplen), data.network = htonl(data.network);
    out.write((char*)&data, sizeof(pcap_hdr));
    return out;
  }
};
struct pcaprec_hdr {
  // 所有字段都是大端序
  uint32_t ts_sec;    // 时间戳（秒）
  uint32_t ts_usec;   // 时间戳（微秒）
  uint32_t incl_len;  // 该片段的存储长度
  uint32_t orig_len;  // 该片段实际的长度
  pcaprec_hdr(std::vector<uint8_t>::const_iterator begin)
      : ts_sec((begin[0] << 24) + (begin[1] << 16) + (begin[2] << 8) +
               (begin[3] << 0)),
        ts_usec((begin[4] << 24) + (begin[5] << 16) + (begin[6] << 8) +
                (begin[7] << 0)),
        incl_len((begin[8] << 24) + (begin[9] << 16) + (begin[10] << 8) +
                 (begin[11] << 0)),
        orig_len((begin[12] << 24) + (begin[13] << 16) + (begin[14] << 8) +
                 (begin[15] << 0)) {
    assert(ts_usec < 1e6 && incl_len == orig_len);
  }
  friend std::ostream& operator<<(std::ostream& out, pcaprec_hdr data) {
    data.incl_len = htonl(data.incl_len), data.orig_len = htonl(data.orig_len),
    data.ts_sec = htonl(data.ts_sec), data.ts_usec = htonl(data.ts_usec);
    out.write((char*)&data, sizeof(pcaprec_hdr));
    return out;
  }
};
struct pcaprec {
  pcaprec_hdr header;
  std::vector<uint8_t> data;
  pcaprec(std::vector<uint8_t>::const_iterator begin)
      : header(begin), data(begin + 16, begin + 16 + header.orig_len) {}
  friend std::ostream& operator<<(std::ostream& out, pcaprec const& data) {
    out << data.header;
    out.write((char*)data.data.data(), data.header.incl_len);
    return out;
  }
};
struct pcap {
  pcap_hdr header;
  std::vector<pcaprec> data;
  pcap(std::vector<uint8_t>::const_iterator begin,
       std::vector<uint8_t>::const_iterator end)
      : header(begin), data() {
    begin += 24;
    while (begin != end)
      data.emplace_back(begin), begin += data.back().header.orig_len + 16;
  }
  pcap(pcap_hdr const& p): header(p), data() {}
  friend std::ostream& operator<<(std::ostream& out, pcap const& data) {
    out << data.header;
    for (pcaprec const& i : data.data) out << i;
    return out;
  }
};
struct ethernet_frame {
  std::array<uint8_t, 6> destinationMAC, sourceMAC;
  enum class EtherType : uint16_t { ipv4 = 0x0800, arp = 0x0806 } etherType;
  std::vector<uint8_t> data;
  uint32_t fcs;

  struct CheckError: PackageCheckError {};

  ethernet_frame(pcaprec const& f)
      : ethernet_frame(f.data.begin(), f.data.end()) {}
  ethernet_frame(std::vector<uint8_t>::const_iterator beg,
                 std::vector<uint8_t>::const_iterator end)
      : destinationMAC{beg[0], beg[1], beg[2], beg[3], beg[4], beg[5]},
        sourceMAC{beg[6], beg[7], beg[8], beg[9], beg[10], beg[11]},
        etherType(EtherType((beg[12] << 8) + (beg[13] << 0))),
        data(beg + 14, end - 4),
        fcs((end[-4] << 24) + (end[-3] << 16) + (end[-2] << 8) +
            (end[-1] << 0)) {
    if (!check(std::vector<uint8_t>(beg, end))) throw CheckError();
  }
  static uint64_t query_check_byte(uint8_t x) {
    static std::array<uint64_t, 256> mem = {};
    static constexpr int64_t G = 0b100000100110000010001110110110111;
    if (mem[x]) return mem[x];
    if (x == 0) return 0;
    uint8_t y = x;
    for (uint8_t i = 7; i < 8; --i)
      if ((x >> i) & 1) x ^= uint8_t(G << i >> 32), mem[y] ^= G << i;
    return mem[y];
  }
  static bool check(std::vector<uint8_t> f) {
    uint32_t fcs;
    std::copy_n(f.end() - 4, 4, (uint8_t*)&fcs), fcs = htonl(fcs);
    std::fill_n(f.end() - 4, 4, 0);
    for (uint8_t& i : f) i = bitreverse(i);
    f[0] = ~f[0], f[1] = ~f[1], f[2] = ~f[2], f[3] = ~f[3];
    for (size_t i = 4; i < f.size(); ++i) {
      int64_t x = query_check_byte(f[i - 4]);
      f[i - 4] ^= uint8_t(x >> (40 - 8)), f[i - 3] ^= uint8_t(x >> (40 - 16)),
          f[i - 2] ^= uint8_t(x >> (40 - 24)),
          f[i - 1] ^= uint8_t(x >> (40 - 32)),
          f[i - 0] ^= uint8_t(x >> (40 - 40));
    }
    uint32_t res = ~((bitreverse((uint32_t)f.rbegin()[3]) << 24u) +
                     (bitreverse((uint32_t)f.rbegin()[2]) << 16u) +
                     (bitreverse((uint32_t)f.rbegin()[1]) << 8u) +
                     (bitreverse((uint32_t)f.rbegin()[0]) << 0u));
    return fcs == res;
  }
};
struct ipgroup_hdr {
  uint8_t version : 4;  // 始终为 0b0100
  uint8_t ihl : 4;
  uint8_t type;  // 始终为 0
  uint16_t total_length;
  uint16_t identification;
  uint8_t flag : 3;      // 始终为 0b010
  uint16_t offset : 13;  // 始终为 0
  uint8_t time_to_live;
  uint8_t protocol;
  uint16_t header_checksum;
  std::array<uint8_t, 4> source_ip, destination_ip;
  std::vector<uint8_t> options;

  struct CheckError: PackageCheckError {};

  ipgroup_hdr(ethernet_frame const& f): ipgroup_hdr(f.data.begin()) {}
  ipgroup_hdr(std::vector<uint8_t>::const_iterator beg)
      : version(beg[0] >> 4),
        ihl(beg[0] & 0xf),
        type(beg[1]),
        total_length((beg[2] << 8) + (beg[3] << 0)),
        identification((beg[4] << 8) + (beg[5] << 0)),
        flag(beg[6] >> 5),
        offset(((beg[6] & 0b00011111) << 8) + (beg[7] << 0)),
        time_to_live(beg[8]),
        protocol(beg[9]),
        header_checksum((beg[10] << 8) + (beg[11] << 0)),
        source_ip{beg[12], beg[13], beg[14], beg[15]},
        destination_ip{beg[16], beg[17], beg[18], beg[19]},
        options(beg + 20, beg + ihl * 4) {
    assert(version == 0b0100 && type == 0 && flag == 0b010 && offset == 0 &&
           identification == 0 && ihl >= 5 && total_length >= 20);
    if (!check(beg)) throw CheckError();
  }
  static bool check(std::vector<uint8_t>::const_iterator beg) {
    size_t n = (beg[0] & 0xf) * 4;
    uint32_t sum = 0;
    for (size_t i = 0; i < n; i += 2)
      if (i != 10) {
        sum += (beg[i + 0] << 8) + (beg[i + 1] << 0);
        uint16_t x;
        while ((x = (sum >> 16))) sum &= 0xffff, sum += x;
      }
    return uint16_t(~sum) == uint16_t((beg[10] << 8) + (beg[11] << 0));
  }
};
struct ipgroup {
  ipgroup_hdr header;
  std::vector<uint8_t> data;
  ipgroup(ethernet_frame const& f): ipgroup(f.data.begin()) {}
  ipgroup(std::vector<uint8_t>::const_iterator beg)
      : header(beg), data(beg + header.ihl * 4, beg + header.total_length) {}
};

int main(void) {
  std::ios::sync_with_stdio(false), std::cin.tie(nullptr),
      std::cout.tie(nullptr);
  std::vector<uint8_t> buf((std::istreambuf_iterator<char>(fin)),
                           std::istreambuf_iterator<char>());
  pcap f(buf.begin(), buf.end());
  for (auto const& i : f.data) try {
      ethernet_frame a(i);
      if (a.etherType == ethernet_frame::EtherType::ipv4) ipgroup b(a);
      std::cout << "Yes\n";
    } catch (PackageCheckError const&) { std::cout << "No\n"; }
  return 0;
}