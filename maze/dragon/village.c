inherit ROOM; 
#include <ansi.h> 
void create()
{
        set("short", "�������");
        set("long",
"[1;32m��ǰ�Ǽ�����Ϊ��ͨ�Ĵ��ᣬ�����������С������������\n"
"׷����֣���ֻ�ʷʵĴ�׶죬�����������쳤�˲��Ӹ¸µĽУ��ƺ���\n"
"�����Ȼ�ҵ����������ÿ��Ϧ�����µ�ʱ�򣬺���é��ձ�ɵ��ݶ�\n"
"��ᱻ�����Ĵ�����ס����������������һ�����˵��׷�����ζ��\n"
);
        set("exits", ([ /* sizeof() == 4 */
   "south" : __DIR__"lake",
   "west" : __DIR__"spirit10",
   "east" : __DIR__"zhanglao",
   ]));

        set("no_magic", 1);
	setup();
        replace_program(ROOM);

}


