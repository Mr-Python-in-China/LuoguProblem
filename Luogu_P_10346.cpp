#include <arpa/inet.h>
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
std::ifstream fin("./data/P10346.in", std::ifstream::binary);
std::ofstream fout("./data/P10346.out", std::ofstream::binary);
#else
std::istream& fin = std::cin;
std::ostream& fout = std::cout;
#endif

template <typename T, size_t n>
const auto array_hash = [](std::array<T, n> const& f) {
  return std::_Hash_impl::hash(f.data(), f.size());
};

std::unordered_map<std::array<uint8_t, 4>, std::array<uint8_t, 6>,
                   decltype(array_hash<uint8_t, 4>)> const
    eths(
        {
            {  {10, 2, 1, 1},{0x98, 0x01, 0x29, 0x00, 0x00, 1}                             },
            {  {10, 2, 2, 1},  {0x98, 0x01, 0x29, 0x00, 0x00, 2}},
            {  {10, 2, 3, 1},  {0x98, 0x01, 0x29, 0x00, 0x00, 3}},
            {  {10, 2, 4, 1},  {0x98, 0x01, 0x29, 0x00, 0x00, 4}},
            {  {10, 2, 5, 1},  {0x98, 0x01, 0x29, 0x00, 0x00, 5}},
            {  {10, 2, 6, 1},  {0x98, 0x01, 0x29, 0x00, 0x00, 6}},
            {  {10, 2, 7, 1},  {0x98, 0x01, 0x29, 0x00, 0x00, 7}},
            {  {10, 2, 8, 1},  {0x98, 0x01, 0x29, 0x00, 0x00, 8}},
            {  {10, 2, 9, 1},  {0x98, 0x01, 0x29, 0x00, 0x00, 9}},
            { {10, 2, 10, 1}, {0x98, 0x01, 0x29, 0x00, 0x00, 10}},
            { {10, 2, 11, 1}, {0x98, 0x01, 0x29, 0x00, 0x00, 11}},
            { {10, 2, 12, 1}, {0x98, 0x01, 0x29, 0x00, 0x00, 12}},
            { {10, 2, 13, 1}, {0x98, 0x01, 0x29, 0x00, 0x00, 13}},
            { {10, 2, 14, 1}, {0x98, 0x01, 0x29, 0x00, 0x00, 14}},
            { {10, 2, 15, 1}, {0x98, 0x01, 0x29, 0x00, 0x00, 15}},
            { {10, 2, 16, 1}, {0x98, 0x01, 0x29, 0x00, 0x00, 16}},
#ifndef ONLINE_JUDGE
            {{10, 2, 12, 82},
             {0x98, 0x01, 0x29, 0x00, 0x00, 114}                }, // test，提交时删除
#endif
},
        16, array_hash<uint8_t, 4>);

u_int8_t bitreverse(uint8_t x) {
  x = ((x & 0xaa) >> 1) | ((x & 0x55) << 1);
  x = ((x & 0xcc) >> 2) | ((x & 0x33) << 2);
  x = ((x & 0xf0) >> 4) | ((x & 0x0f) << 4);
  return x;
}

struct Throwable {};
struct PackageCheckError: Throwable {};
struct UnknownTargetError: Throwable {};

struct pcap_hdr {
  // 所有字段都是大端序
  uint32_t magic_number;   // 用于文件类型识别，始终为 0xA1B2C3D4，
  uint16_t version_major;  // 始终为 2
  uint16_t version_minor;  // 始终为 4
  int32_t thiszone;        // 始终为 0
  uint32_t sigfigs;        // 始终为 0
  uint32_t snaplen;        // 允许的最大包长度，始终为 262144
  uint32_t network;  // 数据类型，本次学习题中始终为 1 （以太网）
  pcap_hdr(void)
      : magic_number(0xA1B2C3D4),
        version_major(2),
        version_minor(4),
        thiszone(0),
        sigfigs(0),
        snaplen(262144),
        network(1) {}
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
  pcaprec_hdr(size_t len): ts_sec(), ts_usec(), incl_len(len), orig_len(len) {}
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
  pcaprec(std::vector<uint8_t> const& d): header(d.size()), data(d) {}
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
  pcap(void): header(), data() {}
  pcap(pcap_hdr const& p): header(p), data() {}
  pcap(std::vector<uint8_t>::const_iterator begin,
       std::vector<uint8_t>::const_iterator end)
      : header(begin), data() {
    begin += 24;
    while (begin != end)
      data.emplace_back(begin), begin += data.back().header.orig_len + 16;
  }
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

  ethernet_frame(std::array<uint8_t, 6> const& _desMAC,
                 std::array<uint8_t, 6> const& _srcMAC, EtherType _t,
                 std::vector<uint8_t> const& _d)
      : destinationMAC(_desMAC),
        sourceMAC(_srcMAC),
        etherType(_t),
        data(_d),
        fcs() {  // getbuffer 中直接取了 fcs
                 // 的值，直接调用初始化访问未分配内存产生 UB
    fcs = get_fcs(tobuffer());
  }
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
    if (!check()) throw CheckError();
  }
  static uint64_t query_fcs_byte(uint8_t x) {
    static std::array<uint64_t, 256> mem = {};
    static constexpr int64_t G = 0b100000100110000010001110110110111;
    if (mem[x]) return mem[x];
    if (x == 0) return 0;
    uint8_t y = x;
    for (uint8_t i = 7; i < 8; --i)
      if ((x >> i) & 1) x ^= uint8_t(G << i >> 32), mem[y] ^= G << i;
    return mem[y];
  }
  static uint32_t get_fcs(std::vector<uint8_t> f) {
    std::fill_n(f.end() - 4, 4, 0);
    for (uint8_t& i : f) i = bitreverse(i);
    f[0] = ~f[0], f[1] = ~f[1], f[2] = ~f[2], f[3] = ~f[3];
    for (size_t i = 4; i < f.size(); ++i) {
      int64_t x = query_fcs_byte(f[i - 4]);
      f[i - 4] ^= uint8_t(x >> (40 - 8)), f[i - 3] ^= uint8_t(x >> (40 - 16)),
          f[i - 2] ^= uint8_t(x >> (40 - 24)),
          f[i - 1] ^= uint8_t(x >> (40 - 32)),
          f[i - 0] ^= uint8_t(x >> (40 - 40));
    }
    uint32_t res = ~((bitreverse((uint32_t)f.rbegin()[3]) << 24u) +
                     (bitreverse((uint32_t)f.rbegin()[2]) << 16u) +
                     (bitreverse((uint32_t)f.rbegin()[1]) << 8u) +
                     (bitreverse((uint32_t)f.rbegin()[0]) << 0u));
    return res;
  }
  bool check(void) { return fcs == get_fcs(tobuffer()); }
  std::vector<uint8_t> tobuffer(void) {
    std::vector<uint8_t> res{destinationMAC[0],
                             destinationMAC[1],
                             destinationMAC[2],
                             destinationMAC[3],
                             destinationMAC[4],
                             destinationMAC[5],
                             sourceMAC[0],
                             sourceMAC[1],
                             sourceMAC[2],
                             sourceMAC[3],
                             sourceMAC[4],
                             sourceMAC[5],
                             uint8_t(uint16_t(etherType) >> 8),
                             uint8_t(uint16_t(etherType) >> 0)};
    res.insert(res.end(), data.begin(), data.end());
    while (res.size() < 64 - 4) res.push_back(0);  // 长度至少为 64
    res.insert(res.end(), {uint8_t(fcs >> 24), uint8_t(fcs >> 16),
                           uint8_t(fcs >> 8), uint8_t(fcs >> 0)});
    return res;
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
struct arp {
  uint16_t hardware_type;  // 总是 1
  uint16_t protocol_type;  // 总是 0x0800
  uint8_t hlen;            // 总是 0x6
  uint8_t plen;            // 总是 0x4
  enum class OPCode : uint16_t { request = 1, response = 2 } opcode;
  std::array<uint8_t, 6> sha;
  std::array<uint8_t, 4> spa;
  std::array<uint8_t, 6> tha;
  std::array<uint8_t, 4> tpa;

  struct OPCodeNotRequest: UnknownTargetError {};
  struct IPNotFound: UnknownTargetError {};

  arp(OPCode _type, std::array<uint8_t, 6> const& _sha,
      std::array<uint8_t, 4> const& _spa, std::array<uint8_t, 6> const& _tha,
      std::array<uint8_t, 4> const& _tpa)
      : hardware_type(1),
        protocol_type(0x0800),
        hlen(6),
        plen(4),
        opcode(_type),
        sha(_sha),
        spa(_spa),
        tha(_tha),
        tpa(_tpa) {}
  arp(ethernet_frame const& f): arp(f.data.begin()) {}
  arp(std::vector<uint8_t>::const_iterator beg)
      : hardware_type((beg[0] << 8) + (beg[1] << 0)),
        protocol_type((beg[2] << 8) + (beg[3] << 0)),
        hlen(beg[4]),
        plen(beg[5]),
        opcode(OPCode((beg[6] << 8) + (beg[7] << 0))),
        sha{beg[8], beg[9], beg[10], beg[11], beg[12], beg[13]},
        spa{beg[14], beg[15], beg[16], beg[17]},
        tha{beg[18], beg[19], beg[20], beg[21], beg[22], beg[23]},
        tpa{beg[24], beg[25], beg[26], beg[27]} {
    assert(hardware_type == 1 && protocol_type == 0x0800 && hlen == 6 &&
           plen == 4);
  }
  std::vector<uint8_t> tobuffer(void) {
    return {uint8_t(hardware_type >> 8),
            uint8_t(hardware_type >> 0),
            uint8_t(protocol_type >> 8),
            uint8_t(protocol_type >> 0),
            hlen,
            plen,
            uint8_t((uint16_t)opcode >> 8),
            uint8_t((uint16_t)opcode >> 0),
            sha[0],
            sha[1],
            sha[2],
            sha[3],
            sha[4],
            sha[5],
            spa[0],
            spa[1],
            spa[2],
            spa[3],
            tha[0],
            tha[1],
            tha[2],
            tha[3],
            tha[4],
            tha[5],
            tpa[0],
            tpa[1],
            tpa[2],
            tpa[3]};
  }
  arp get_response(void) {
    if (opcode != OPCode::request) throw OPCodeNotRequest();
    auto it = eths.find(tpa);
    if (it == eths.end()) throw IPNotFound();
    return arp(OPCode::response, it->second, it->first, sha, spa);
  };
};

int main(void) {
  std::ios::sync_with_stdio(false), std::cin.tie(nullptr),
      std::cout.tie(nullptr);
  std::vector<uint8_t> buf((std::istreambuf_iterator<char>(fin)),
                           std::istreambuf_iterator<char>());
  pcap f(buf.begin(), buf.end()), g;
  for (auto const& i : f.data) try {
      ethernet_frame e(i);
      if (e.etherType != ethernet_frame::EtherType::arp) continue;
      arp s(e);
      arp t(s.get_response());
      ethernet_frame f(t.tha, t.sha, ethernet_frame::EtherType::arp,
                       t.tobuffer());
      g.data.emplace_back(f.tobuffer());
    } catch (Throwable const&) {}  // 忽略校验错误、发送者
  fout << g;
}