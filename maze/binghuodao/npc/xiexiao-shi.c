#include <ansi.h>

inherit NPC;

int move_bhd();
int join_battle();

void create()
{
        set_name(HIM "л��ʫ" NOR, ({ "xiexiao shi", "xiexiao", "shi" }));
        set("title", HIW "��" HIR "��" HIC "ʹ��");
        set("long", "���Ǹ�������ҵ����𵺵�����ʹ�ߡ�\n");
        set("gender", "Ů��");
        set("age", 20);
        set("max_qi", 99999);
        set("qi", 99999);
        set("max_jingli", 99999);
        set("max_jing", 99999);
        set("max_neili", 99999);
        set("jing", 99999);
        set("jingli", 99999);
        set("neili", 99999);

        set("per", 25);
        set("con", 88);
        set("int", 88);
        set("dex", 88);
        set("str", 88);

        set("inquiry", ([
                "����" : (: move_bhd :),
                "��������ս" : (: join_battle :),
        ]));
        set("combat_exp", 10000000);
        set("shen_type", 1);
        setup();
        carry_object("/d/city/npc/cloth/feature")->wear();      
}

int move_bhd()
{
        object me = this_player();
        
        // ����Ǯ����
        if( query("balance", me)<100 )
        {
                command("say ����������ƺ�ȱǮ�ɣ��һ����㵽�������ٵ�һ�����ƽ�");
                return 1;
        }
        addn("balance", -100, me);
        
        command("say ��Ȼ��ˣ��Ҿͻ����㵽���𵺰ɣ�");

        me->move("/maze/binghuodao/haitan"); 
        return 1;
}

int join_battle()
{
        object me = this_player();
        BUNCH_D->join_battle(me);
        return 1;
}

