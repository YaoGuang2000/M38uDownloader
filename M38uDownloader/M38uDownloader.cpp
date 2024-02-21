#include <iostream>
#include <cstring>
#include <cstdio>
#include <windows.h>
void downloadAndConvert(const char* m3u8_url, const char* mp4_file) {
    std::string cmd = "ffmpeg -i ";
    cmd += m3u8_url;
    cmd += " -c copy ";
    cmd += mp4_file;
    cmd += " -threads 8";
    cmd += " -y"; 
    std::cout << "开始下载和转换视频，请稍候...\n";
    for (int i = 0; i < 100; i += 5) {
        std::cout << "\r["; 
        for (int j = 0; j < i; j += 5) std::cout << "=";
        std::cout << ">"; 
        for (int k = i + 5; k < 100; k += 5) std::cout << " ";
        std::cout << "]";
        std::cout.flush(); 
        Sleep(1000); 
    }
    std::cout << "\n完成!\n";
    system(cmd.c_str());
}
void downloadStreamAsMKV(const char* m3u8_url, const char* output_mkv) {
    std::string cmd = "ffmpeg -i ";
    cmd += m3u8_url;
    cmd += " -c copy";
    cmd += " -f matroska";
    cmd += " -y "; 
    cmd += output_mkv;
    system(cmd.c_str());
}
using namespace std;
int main() {
    string m3u8_url = "";
    cout << "请输入m3u8地址" << endl;
    cin >> m3u8_url;
    cout << "m3u8地址为：" << m3u8_url << endl;
    cout << "请输入下载文件的名字(自定义)"<<endl;
    string output_mp4 = ""; 
    cin >> output_mp4;
    string outputfile = output_mp4+".mkv";
    downloadStreamAsMKV(m3u8_url.c_str(), outputfile.c_str());
    return 0;
}