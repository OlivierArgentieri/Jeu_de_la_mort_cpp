#include "pch.h"
#include "Case.h"

char Case::GetChar()
{
	if (this->m_ptr_humanoid != nullptr)
		return this->m_ptr_humanoid->GetSprite();

	return this->m_char_;
}
