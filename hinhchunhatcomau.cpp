#include "graphics.h"
main()
{
		int mh=mode=0;
		initegraph(&mh,&mode,"");
		if (graphresult != grOk) 
			exit(1);
		setbkcolor(GREEN);
		setcolor(RED);
		setfillstyle(CLOSE_DOT_FILL,YELLOW);
		rectangle(5,5,300,160);
		bar(3,175,300,340);
		bar3d(320,100,500,340,100,1);
		closegraph();
		
}
