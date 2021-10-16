#include "Animation.h"

void Animation::move(Dir dir, int step /*= 1*/)
{
	Pencil p(*ui);
	switch (dir)
	{
	case Dir::none: 
		break;
	case Dir::up:
		ui->replace(c);
		cdnt.y -= step;
		p.Pixel(cdnt,c);//其实可以给Scene写一个方法——在指定的坐标放下一个字符，这样就可以不用Pencil了
		break;
	case Dir::down:
		ui->replace(c);
		cdnt.y += step;
		p.Pixel(cdnt, c);
		break;
	case Dir::left:
		ui->replace(c);
		cdnt.x -= step;
		p.Pixel(cdnt, c);
		break;
	case Dir::right:
		ui->replace(c);
		cdnt.x += step;
		p.Pixel(cdnt, c);
		break;
	default:
		break;
	}
}

void Animation::refresh(Dir dir,int step/*= 1*/)
{
	move(dir,step);
}

Animation& Animation::select(Coordinate cdnt)
{
	this->cdnt = cdnt;
	c = ui->look(cdnt);
	return *this;
}
