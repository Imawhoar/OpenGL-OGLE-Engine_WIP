#pragma once
#include <filesystem>

typedef std::filesystem::path PathDirectory;

namespace FileHandler {
	
	inline std::string GetSolutionPath() {
		auto temp = std::filesystem::current_path().generic_string();
		return temp;
	}

	inline std::string GetResourcePath() {
		auto temp = std::filesystem::current_path();
		temp.append("Resources");
		return temp.generic_string();
	}

	/// Tries to get the path to file recursively. 
	inline std::string FindFile(PathDirectory entryDir, const char* fileName) {

		if (!std::filesystem::exists(entryDir) || !std::filesystem::is_directory(entryDir))
			return "";

		for (const auto& currentPath : std::filesystem::directory_iterator(entryDir))
		{

			if (std::filesystem::is_directory(currentPath.path()))
			{
				PathDirectory path = FindFile(currentPath.path(), fileName);

				if (path.empty())
					continue;

				return path.generic_string();
			}
			else
			{
				if (currentPath.path().filename() == fileName)
					return currentPath.path().generic_string();
			}
		}
		return "";
	}
	std::string FindFile(const char* fileName) { return FindFile(GetSolutionPath(), fileName); }
	std::string FindResource(const char* fileName) { return FindFile(GetResourcePath(), fileName); }


	inline void RenameFile(PathDirectory filePath, const char* newName) {

		if (!std::filesystem::exists(filePath)) {
			std::cout << "[FILEHANDLER -> RenameFile -> filePath] Path does not exist";
			return;
		}

		std::filesystem::rename(filePath, newName);
	}

	inline void CopyFile(const PathDirectory& from, const PathDirectory to) {
		if (!std::filesystem::exists(from)) {
			std::cout << "[FILEHANDLER -> CopyFile -> from] Path does not exist";
			return;
		}
		else if (!std::filesystem::exists(to)) {
			std::cout << "[FILEHANDLER -> RenameFile -> to] Path does not exist";
			return;
		}
		std::filesystem::copy(from, to);
	}

	inline void RemoveFile(PathDirectory path) {
		if (!std::filesystem::exists(path)) {
			std::cout << "[FILEHANDLER -> RemoveFile] Path does not exist";
			return;
		}

		std::filesystem::remove(path);
	}

}