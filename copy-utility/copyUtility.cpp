#include <filesystem>
#include <fstream>
#include <iostream>
#include <system_error>

namespace fs = std::filesystem;

void copyFile(const fs::path &source, const fs::path &dest) {
  // Check if the source file exists
  if (!fs::exists(source)) {
    std::cerr << "Error: Source file does not exist." << std::endl;
    return;
  }

  // Check if the destination file already exists
  if (fs::exists(dest)) {
    std::cerr
        << "Error: Destination file already exists. Overwriting is not allowed"
        << std::endl;
    return;
  }

  // Open source file
  std::ifstream s(source, std::ios::binary);
  if (!s) {
    std::cerr << "Error: Failed to open source file." << std::endl;
    return;
  }

  // Open destination file
  std::ofstream d(dest, std::ios::binary);
  if (!d) {
    std::cerr << "Error: Failed to open destination file." << std::endl;
    return;
  }

  // Get the size of the source file
  std::uintmax_t sz = fs::file_size(source);

  // Copy the source file into the destination file
  const std::size_t bufferSize = 4096; // 4KB
  char buffer[sz];

  std::uintmax_t bytesRead = 0;
  while (bytesRead < sz) {
    if (!s || !d) {
      std::cerr << "Error: Failed to copy data" << std::endl;
      return;
    }
    s.read(buffer, bufferSize);
    std::streamsize bytes = s.gcount();

    d.write(buffer, bytes);

    bytesRead += bytes;
  }

  std::cout << "Copied: " << source << " -> " << dest << std::endl;
}

void copyDirectory(const fs::path &source, const fs::path &destination) {
  // Create the destination directory if it doesn't exist
  if (!fs::exists(destination)) {
    fs::create_directories(destination);
    std::cout << "Created directory: " << destination << std::endl;
  }

  // Iterate over all files and subdirectories in the source directory
  for (const auto &entry : fs::directory_iterator(source)) {
    const auto &path = entry.path();
    auto relativePath = path.lexically_relative(source);
    auto targetPath = destination / relativePath;

    if (fs::is_directory(path)) {
      // Recursively copy subdirectories
      copyDirectory(path, targetPath);
    } else if (fs::is_regular_file(path)) {
      // Copy files
      if (fs::exists(targetPath)) {
        std::cerr << "Error: File already exists (skipping): " << targetPath
                  << std::endl;
      } else {
        copyFile(path, targetPath);
      }
    }
  }

  std::cout << "Directory copied successfully." << std::endl;
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    std::cerr << "Usage: " << argv[0] << " <source file> <destination file>"
              << std::endl;
    return -1;
  }

  fs::path sourcePath = fs::absolute(argv[1]);
  fs::path destPath = fs::absolute(argv[2]);

  if (!fs::exists(sourcePath)) {
    std::cerr << "Error: Source path does not exist: " << sourcePath
              << std::endl;
    return -1;
  }

  if (fs::is_directory(sourcePath)) {
    copyDirectory(sourcePath, destPath);
  } else if (fs::is_regular_file(sourcePath)) {
    if (fs::exists(destPath)) {
      std::cerr << "Error: Destination file already exists: " << destPath
                << std::endl;
    } else {
      copyFile(sourcePath, destPath);
    }
  } else {
    std::cerr << "Error: Source is not a file or directory: " << sourcePath
              << std::endl;
  }

  return 0;
}
