#include <ansi.h> 
inherit ROOM;

void create()
{
        set("short", HIC"ʧ������"NOR);
        set("long", @LONG
����ܴ������ϵ����ǧ��ٹֵĶ���е�������ȴ
����һ����ͷ������������һ˫��򣬹���Ĺ��׵ĵ������
̾Ϊ��ֹ�����ɰ˽ǣ��ݼ���������,����,���,ľ��,�ʻ�
��Ϊ��Ʒ��
LONG);
        
        set("maze", 1);
        set("no_magic", 1);
        set("virtual_room", 1);
        set("no_clean_up", 1);       
        set("objects",([
                "/maze/temple/npc/zombie": 10,  
                "/maze/temple/npc/zombie_lord": 3,
                "/maze/temple/npc/zombie_king": 1,
        ]));
        setup();
}

