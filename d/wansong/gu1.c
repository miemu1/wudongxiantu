// This program is a part of NITAN MudLIB

inherit ROOM;
#include <room.h>

void create()
{
        int i;
        object girl;
        set("short", "����");
        set("long", @LONG
Ϫ������������������ˮ�ϣ���ֻ�����ڻ����з�����ȥ����
ƺ�����ռ䣬б���ż���������Ů��������ɴ���������ۣ�����ӯӯ
ǳЦ���������
LONG );
        set("exits", ([ /* sizeof() == 4 */
                "south" : __DIR__"gu0",
                "west" : __DIR__"gu2",
      
        ]));  
        set("objects", ([
                CLASS_D("mojiao/chunhua") : 1,
                CLASS_D("mojiao/qiuyue") : 1,
        ]) );
        set("outdoors","wansong");      
        set("coor/x",120);
        set("coor/y",10);
        set("coor/z",10);
        setup(); 
} 
