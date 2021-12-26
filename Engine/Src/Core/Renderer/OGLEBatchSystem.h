#pragma once
#include <vector>
#include "oglepch.h"
namespace OGLE
{

	//TODO: Will implement...
	//Only got static for now
	enum class BatchDrawType
	{
		//Dynamic = GL_DYNAMIC_DRAW,
		Static = GL_STATIC_DRAW,
		//Stream = GL_STREAM_DRAW,
	};

	class Batch final
	{
	private:
		unsigned int m_vao = 0;
		unsigned int m_vbo = 0;
		unsigned int m_priority;

		BatchDrawType m_drawType;

		//How many rects CAN we store in this batch. Can change.
		unsigned int m_maxRectCount = 100000;

		//How many rects HAVE we stored in this batch
		unsigned int m_occupiedRectCount = 0;


	};

	class BatchManager final
	{
		std::vector<Batch*> m_batches;
	};
}
