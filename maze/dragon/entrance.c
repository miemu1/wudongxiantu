inherit ROOM; 
#include <ansi.h> 

void create()
{
      set("short","���ƺ");
      set("long",
"[1;32m��������࣬���������������е��������㡣ԶԶ�ɼ�ɽ\n"
"���������𣬲�ϼ�����硣���ϻ���һ��Ȫ�ۣ����������ƺ��Ѿ��ɺ��ˡ�\n"
);
      set("exits",([ 
           "north"  : __DIR__"spirit4",
      ]));
      set("objects",([
      ]));
      set("no_magic", 1);
	setup();
}

