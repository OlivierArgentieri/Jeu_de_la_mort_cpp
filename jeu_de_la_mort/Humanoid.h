#pragma once
class Humanoid
{
protected:
	~Humanoid() = default;
public:
	virtual void Walk();

	void TryTouch();
	virtual bool CanTouch() = 0;
	virtual void Touch() = 0;
};