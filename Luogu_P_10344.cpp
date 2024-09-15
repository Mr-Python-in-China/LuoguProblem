#include <arpa/inet.h>
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
std::ifstream fin("./data/P10344.in", std::ifstream::binary);
std::ofstream fout("./data/P10344.out", std::ofstream::binary);
#else
std::istream& fin = std::cin;
std::ostream& fout = std::cout;
#endif
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
} __attribute__((packed));
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
} __attribute__((packed));
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
int main(void) {
  std::ios::sync_with_stdio(false), std::cin.tie(nullptr),
      std::cout.tie(nullptr);
  std::vector<uint8_t> buf((std::istreambuf_iterator<char>(fin)),
                           std::istreambuf_iterator<char>());
  pcap f(buf.begin(), buf.end());
  pcap nf(f.header);
  for (auto i : f.data)
    if (i.header.orig_len <= 1000) nf.data.push_back(i);
  sort(nf.data.begin(), nf.data.end(), [](pcaprec const& a, pcaprec const& b) {
    return (a.header.ts_sec) * (uint64_t)1e6 + a.header.ts_usec <
           (b.header.ts_sec) * (uint64_t)1e6 + b.header.ts_usec;
  });
  fout << nf;
  return 0;
}