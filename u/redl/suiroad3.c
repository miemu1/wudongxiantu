// This program is a part of NITAN MudLIB 
// redl 2013/4
#include <ansi.h> 
#include <room.h> 
inherit ROOM; 

void create() 
{ 
                set("short", "ɽ��С��"); 
                        set("long", @LONG
������ɽ���ϵ��ػ����۵�С��������ϼε�����Ѷ��ϣ�����ȴ
������׵ľ���Ͽ�ȡ�·�ߵ�ʯ���ּ䣬�������ʢ����һ�Դ���
��������ĸ�ɽ�ž黨��
LONG );
                                

                set("exits", ([ /* sizeof() == */ 
                        "eastdown" : __DIR__"suiroad2",
                        "northup" : __DIR__"suistone",
                ])); 

                set("no_rideto", 1);
                set("no_flyto", 1);
                setup(); 
} 


