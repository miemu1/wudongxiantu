// This program is a part of NITAN MudLIB

inherit ROOM;
#include <room.h>

void create()
{       
        object con, item;
        set("short", "����ǰ");
        set("long", @LONG
�˴�һƬ�տ���ǳ���������������һƬ����֮�ϣ�������ʮ
��������ɫ���ټ�����գ��尸֮�����쳾����̻����£��ƺ�����
��Ⱥɽ���衣
LONG );
        set("exits", ([ /* sizeof() == 4 */
                "eastup" : __DIR__"gu2",
                "westdown" : __DIR__"gu4",
 
        ])); 
        set("objects", ([
                __DIR__"obj/qinji" : 1,
        ])); 
        set("outdoors","wansong");              
         
        set("coor/x",100);
        set("coor/y",10);
        set("coor/z",0);
        setup(); 
}   
