#pragma once
#include <sys/mount.h>
#include <sys/stat.h>
#include <unistd.h>

#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
template <typename T>
static void lock_val(const T &value, const char *path)
{
    if (!std::filesystem::exists(path)) {
        // LOG("Warning: ", path, " 不存在");
        return;
    }
    umount(path);

    // chown(TmpPath,0,0);
    chmod(path, 0666);
    // target_file:path
    // 对象

    std::ofstream target_file(path, std::ios::out | std::ios::trunc);
    if (!target_file.is_open()) {
        std::cerr << "无法打开文件进行写操作: " << path << std::endl;
        return;
    }

    target_file << value;
    target_file.close();

    chmod(path, 0555);

}
