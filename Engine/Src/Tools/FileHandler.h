#pragma once
#include <filesystem>
#include <iostream>

using PathDirectory = std::filesystem::path;

namespace OGLE::FileHandler
{
	inline std::string GetSolutionPath()
	{
		auto temp = std::filesystem::current_path().generic_string();
		return temp;
	}

	inline std::string GetResourcePath()
	{
		auto temp = std::filesystem::current_path();
		temp.append("Resources");
		return temp.generic_string();
	}

	/// Tries to get the path to file recursively. 
	inline std::string GetFilePath(const PathDirectory& entryDir, const char* fileName)
	{
		if (!exists(entryDir) || !is_directory(entryDir))
			return "";

		for (const auto& currentPath : std::filesystem::directory_iterator(entryDir))
		{
			if (is_directory(currentPath.path()))
			{
				PathDirectory path = GetFilePath(currentPath.path(), fileName);

				if (path.empty())
					continue;

				return path.generic_string();
			}
			if (currentPath.path().filename() == fileName)
				return currentPath.path().generic_string();
		}
		return "";
	}

	inline std::string GetFilePath(const char* fileName) { return GetFilePath(GetSolutionPath(), fileName); }
	inline std::string GetResourcePath(const char* fileName) { return GetFilePath(GetResourcePath(), fileName); }


	inline void RenameFile(const PathDirectory& filePath, const char* newName)
	{
		if (!exists(filePath))
		{
			std::cout << "[FILEHANDLER -> RenameFile -> filePath] Path does not exist";
			return;
		}

		std::filesystem::rename(filePath, newName);
	}

	inline void CopyFile(const PathDirectory& from, const PathDirectory& to)
	{
		if (!exists(from))
		{
			std::cout << "[FILEHANDLER -> CopyFile -> from] Path does not exist";
			return;
		}
		if (!exists(to))
		{
			std::cout << "[FILEHANDLER -> RenameFile -> to] Path does not exist";
			return;
		}
		copy(from, to);
	}

	inline void RemoveFile(const PathDirectory& path)
	{
		if (!exists(path))
		{
			std::cout << "[FILEHANDLER -> RemoveFile] Path does not exist";
			return;
		}

		std::filesystem::remove(path);
	}
}
