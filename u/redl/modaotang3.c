// This program is a part of NITAN MudLIB 
// redl 2013/1/1

#include <ansi.h> 
#include <room.h>

inherit PRIVATE_ROOM;

void create()
{
        set("short", RED "ĥ����" NOR);
        set ("long", "������ĥ�������˺������������ĵط�(�޳���)��\n"
        "    �����ṩ��ָ��������(reset)������(pfset)��\n");

                set("no_rideto", 1);
                set("no_flyto", 1);
                set("no_sleep_room", 1);
        setup();
}

int do_reset()
{
        mapping ob; 
        object *obs;
        
        obs = all_inventory(); 
        if (sizeof(obs) > 0) 
        { 
                if (arrayp(query_temp("objects"))) 
                        obs -= query_temp("objects"); 
                obs = filter_array(obs, (: ! $1->is_user() :));
                if (sizeof(obs) > 0) 
                { 
                        obs = obs[0..<1]; 
                        foreach (ob in obs) destruct(ob); 
                } 
        } 
        new(__DIR__"npc/tie")->move(this_object());
        new(__DIR__"npc/tie")->move(this_object());
        new(__DIR__"npc/tie")->move(this_object());
new("/d/city/npc/liumang")->move(this_object());
new("/d/city/npc/liumang")->move(this_object());
new("/d/city/npc/liumang")->move(this_object());
new("/d/city/npc/liumang")->move(this_object());
new("/d/city/npc/liumang")->move(this_object());
new("/d/city/npc/liumang")->move(this_object());
        new("/clone/goods/zhufu_armor")->move(this_object());
        new("/clone/goods/zhufu_blade")->move(this_object());
        new("/clone/goods/zhufu_boots")->move(this_object());
        new("/clone/goods/zhufu_cloth")->move(this_object());
        new("/clone/goods/zhufu_finger")->move(this_object());
        new("/clone/goods/zhufu_hammer")->move(this_object());
        new("/clone/goods/zhufu_hand")->move(this_object());
        new("/clone/goods/zhufu_head")->move(this_object());
        new("/clone/goods/zhufu_staff")->move(this_object());
        new("/clone/goods/zhufu_surcoat")->move(this_object());
        new("/clone/goods/zhufu_sword")->move(this_object());
        new("/clone/goods/zhufu_waist")->move(this_object());
        new("/clone/goods/zhufu_whip")->move(this_object());
        new("/clone/goods/zhufu_wrists")->move(this_object());
        message_vision(YEL "$N���������\n" NOR, this_player());
        return 1;
}

int do_pfset(string arg)
{
                string sk, pf;
        if (! arg) return notify_fail("��ȷ��ʽ��pfset ����id�� ����id��\n");
        if (sscanf(arg, "%s %s", sk, pf) != 2) return notify_fail("��ȷ��ʽ��pfset ����id�� ����id��\n");
                set("can_perform/"+ sk +"/" + pf, 1, this_player()); 
                message_vision(YEL "$N������" + sk + "���¾���" + pf + "��\n" NOR, this_player());
                return 1;
}

int init() 
{ 
                object me = this_player();
/*
                if (playerp(me) && !wizardp(me)) {
                        message_vision(YEL "һ���罫$N����������\n" NOR, me);
                        me->move(__DIR__"workroom");
                        return 1;
                }
*/
                add_action("do_reset","reset"); 
                add_action("do_pfset","pfset"); 
                return 1;
} 


