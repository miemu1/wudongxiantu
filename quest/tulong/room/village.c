inherit ROOM; 
#include <ansi.h> 
void create()
{
        set("short", "�������");
        set("long",HIG @LONG 
��ǰ�Ǽ�����Ϊ��ͨ�Ĵ��ᣬ�����������С������������׷
����֣���ֻ�ʷʵĴ�׶죬�����������쳤�˲��Ӹ¸µĽУ���
��������Ȼ�ҵ����������ÿ��Ϧ�����µ�ʱ�򣬺���é��
ձ�ɵ��ݶ���ᱻ�����Ĵ�����ס����������������һ�����˵���
������ζ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
   "south" : "/quest/tulong/room/lake",
   "west" : "/quest/tulong/room/spirit10",
   "east" : "/quest/tulong/room/zhanglao",
//  "northeast" : "/quest/tulong/room/liechang",
   ]));

        setup();
        replace_program(ROOM);

}

