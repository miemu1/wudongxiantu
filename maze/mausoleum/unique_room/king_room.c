#include <ansi.h> 
inherit ROOM;

void create()
{
        set("short", HIY "�ػ�Ĺ��" NOR);
        set("long", @LONG
����������ʼ����Ĺ�����ģ���ǰ�оߺ������ʯ��(coffin)������
������������һ��������--��ʼ�ʡ�
LONG);
        
        set("maze", 1);
        set("no_magic", 1);
        set("virtual_room", 1);
        set("no_clean_up", 1);       
        set("objects",([
                "/maze/mausoleum/unique_room/obj/coffin" : 1,
                "/maze/mausoleum/npc/goldman": 1,  
        ]));
        setup();
}
