// This program is a part of NITAN MudLIB

inherit ROOM;
#include <room.h>

void create()
{
        set("short", "����");
        set("long", @LONG
���������������ԡ�����һ������������ǰһ�Ű�����ɢ����
��ʱ�ʻ�����ɫ�ѹ����Ĵ������羵�������Ӱ��ӳ�뻭�С�
LONG );
        set("exits", ([ /* sizeof() == 4 */ 
                "eastup" : __DIR__"gu4", 
        ])); 
        set("objects",([
                CLASS_D("mojiao/qingqing") : 1,
        ]) );
        set("coor/x",80);
        set("coor/y",10);
        set("coor/z",-20);
        setup();
        create_door("eastup","����","westdown",DOOR_CLOSED);
}  
