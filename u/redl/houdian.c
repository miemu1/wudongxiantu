// This program is a part of NITAN MudLIB 
// redl 2013/5
#include <ansi.h> 
#include <room.h> 
inherit ROOM; 


string look_picture(object me)
{
        if (query("redl/gethomerune", me)<3) {
                add_action("do_kou", "kou");
        return HIC "\n"
        
NOR MAG"�q����r"RED" �q����r" "\n"
NOR MAG"{/ �� ��\\}"RED" {/ �� ��\\}" "\n"
NOR MAG" ( (oo) ) "RED"  ( (oo) )" "\n"
NOR MAG" ����� "RED"  �����" "\n"

"\n" NOR "�㷢�ֻ��ϵ���ͷ���ƺ����Կ�(kou)��...\n" NOR;
        } else {
        return HIC "\n"
        
NOR MAG"�q����r"RED" �q����r" "\n"
NOR MAG"{/ �� ��\\}"RED" {/ �� ��\\}" "\n"
NOR MAG" ( (oo) ) "RED"  ( (oo) )" "\n"
NOR MAG" ����� "RED"  �����" "\n" NOR;
                }
}


void create()
{
        set("short", "���");
        set("long", 
"�����ǻ���������б����Ϲ���һ��"CYN"��"NOR"������ǽ����Ƕ�˸�ʮ��\n"
"��ҹ���飬����״��ţ�ۣ�����������������Ź⻪�����紫˵�еĶ���\n"
"���顣���������������ƣ������˱ǡ�\n"
);
//         set("outdoors", "chengdu");
        set("exits",([ /* sizeof() == 1 */
                "north" : __DIR__"private_room/houyuan",
                "south" : __DIR__"private_room/dadian",
                "east"   : __DIR__"cangku",
                                "west"   : __DIR__"prison",
        ]));

        set("item_desc", ([
                "��": (: look_picture :),
                "hua": (: look_picture :),
                "picture": (: look_picture :),
        ]) );

                set("no_rideto", 1);
                set("no_flyto", 1);
        
        setup();
}

int do_kou()
{
        object me = this_player();
        
        if (!query_temp("can_enterredlroom", me) && query("id", me) != "redl" && query("couple/couple_id", me) != "redl") return notify_fail("���ܽ���������ٺٺټ�Ц�˼�����\n");
        
        if (me->is_busy()) {
                tell_object(me, "����æ�����������˵�ɣ�\n");
                return 1;
        }
        me->start_busy(1);
        
        set_temp("has_kouredlpig", random(2), me);
        
        message_vision(NOR "$N���ʳָ����ָ���������" +((query_temp("has_kouredlpig", me) ? MAG+"����"+NOR : RED+"����"+NOR))+ "�������ǿ�����˿١�\n" NOR, me);
        
        if ( !query_temp("has_kouredl", me) && !random(12) ) {
                message_vision(YEL "ֻ�����ϵ�" +((query_temp("has_kouredlpig", me) ? MAG+"����"+NOR : RED+"����"+NOR))+ YEL + "����ش��˸����磬����ž��һ���鱦����$N���ϡ�\n" NOR, me);
                if (random(2)) new("/clone/tessera/fdiamond")->move(me);
                if (random(2)) new("/clone/tessera/femerald")->move(me);
                if (random(2)) new("/clone/tessera/fsapphire")->move(me);
                if (random(2)) new("/clone/tessera/fruby")->move(me);
                if (random(2)) new("/clone/tessera/ftopaz")->move(me);
                set_temp("has_kouredl", 1, me);//��quit��ڶ����ٻ�����������ǲ�������Ч������       
                addn("redl/gethomerune", 1, me);
                message_vision(CYN + (query_temp("has_kouredlpig", me) ? MAG+"����"+NOR : RED+"����"+NOR) + CYN + "����$Nգգ�ۣ�һ�����ɵúã����������顣\n" + NOR, me);
                message_vision(CYN + (!query_temp("has_kouredlpig", me) ? MAG+"����"+NOR : RED+"����"+NOR) + CYN + "��������$Nһ�ۣ�����һ�����߸ߵİ�ͷ����������\n" + NOR, me);
        }
        return 1;
}


