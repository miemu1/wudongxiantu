// This program is a part of NITAN MudLIB 
// redl 2013/5
#include <ansi.h> 
#include <room.h> 
inherit ROOM; 

void create()
{
        set("short", "����ľ��");
        set("long", 
"','''�q�Шr�Шr.',''',,',.'',,','',.   \n"
"    �u��������''o���������˲���o.'',,',.   \n"
"   ��������辶 '',,',.o��ʯС������̦o   \n"
" �������������������֡֡֩��֡֩��֡֡�\n"
);
         set("outdoors", "chengdu");
         set("exits",([ /* sizeof() == 1 */
                 "westdown" : __DIR__"lakeroad",
                 "enter" : __DIR__"lakehouse2",
                  //"east": "/u/gigi/swing",
         ]));

                set("no_rideto", 1);
                set("no_flyto", 1);
                      set("no_magic", 1); 
        
        setup();
}


