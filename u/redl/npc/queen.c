// This program is a part of NITAN MudLIB 
// redl 2013/4/24 

inherit NPC;
#include <ansi.h>

void create()
{
        set_name("С��Ů" , ({ "shi nv", "girl", "queen" }) );
        set("title", HIY"���ִ��"NOR);
        //set("nickname", HIM "������Ů" NOR);
        set("gender", "Ů��");
        set("age", 21);
        set("long", "����һ���͵�ȴ�߰���Ů�ˣ�ż��Ҳͷ�η�Ƣ����\n");
        set("attitude", "friendly");
        set("str", 21);
        set("con", 19);
        set("int", 36);
        set("dex", 25);
        set("per", 29);
        set("kar", 22);
        set("level",20);
        
        set("max_qi", 100000);
        set("eff_qi", 100000);
        set("qi", 100000);
        set("max_jing", 100000);
        set("eff_jing", 100000);
        set("jing", 100000);
        set("max_neili", 1);
        set("neili", 1);
        set("max_jingli", 1);
        set("jingli", 1);
        
        set("combat_exp", 200000000);

                set("inquiry", ([
               // "����ɢ"   : (: ask_makesan :),
                "��"     : "�㰲�����°ɣ��������ξ��в���ˡ�\n"+NOR,
                "redl"     : "����ū澵������ˣ����Ⱦƣ��Ƚ϶���\n"+NOR,
                "gigi"     : "����ū澵�Ů���ˣ�����Ư����������˫��\n"+NOR,
        ]));

        setup();
        //carry_object("/d/city/npc/cloth/moon-dress")->wear();
        carry_object("/d/city/npc/cloth/zi-dress")->wear();
        
}


void fullnow(object me)
{
    mapping my;
        delete_temp("block_msg/all", me);
        my = me->query_entire_dbase();
        my["jing"]   = my["eff_jing"]   = my["max_jing"]; 
        my["jingli"] = my["eff_jingli"] = my["max_jingli"]; 
        my["qi"]     = my["eff_qi"]     = my["max_qi"]; 
        my["neili"]  = my["max_neili"];
        my["water"]  = my["food"] = 0;
        me->clear_condition();
        me->stop_busy();
        me->clear_weak();
        me->full_self();
        me->remove_all_enemy();
}


int is_owner(object me)
{
        if ( query("id", me) != "redl" && query("couple/couple_id", me) != "redl" ) return 0;
        return 1;
}

void init() 
{ 
        object me = this_player();
        if (playerp(me)) {
                if (!query_temp("has_healredlroom", me)){
                        set_temp("has_healredlroom", 1, me);
                        message_vision(YEL "$N΢΢���ǳЦ����ʱ$n���崺��һ�㾫���ˡ�\n" NOR, this_object(), me);
                        fullnow(me);
                }
                if ( is_owner(me) ){
                        add_action("do_expel", ({"expel", "quzhu"})); 
                        add_action("do_sm", ({"sm", "da"})); 
                        add_action("do_cpat", "cpat"); 
                }
        }
} 

int do_expel(string arg)
{
        object me, ob, where, *ulist;
        
        me = this_player();
        if ( !is_owner(me) ){
                tell_object(me, NOR"���޷���ʹ����Ȩ��\n"NOR);
                return 1;
        }
        
        if (!arg || arg=="") {
                ulist  =  users();
                foreach (ob in ulist) {
                        if (is_owner(ob)) continue;
                        where = environment(ob);
                if (!where) continue;
                if (sscanf(base_name(where), "/u/redl/%*s") ||
                        sscanf(base_name(where), "/data/room/redl/%*s") ||
                        sscanf(base_name(where), "/u/gigi/%*s") ||
                        sscanf(base_name(where), "/data/room/gigi/%*s")) {
                                message_vision(YEL "$N���˸���ָ�������ӿ���ĸ�������ʿ�ֳֳ����ĸ���ǹꪣ�\n"
                                                                   "  ��$n�߸ߵز������棬���һ������...�� ������ʯ��������ȥ��\n" NOR, this_object(), ob);
                                delete_temp("can_enterredlroom", ob);
                                ob->move("/u/redl/private_room/dating");
                                message_vision(YEL "$N��ʯ���Ϲ�µ��µ��������ˤ�˸��߻���أ����ڵ����޷�������\n" NOR, ob);
                                ob->start_busy(30);
                        }
                }
                return 1;
        }
        
        ob = find_player(arg);
        if (!ob || !objectp(ob) || !playerp(ob)) {
                tell_object(me, "��û�з���������ҡ�\n");
                return 1;
        }

        //����summ���������޷����ͨ������ʸ�
        message_vision(YEL "$N���˸���ָ�������ӿ���ĸ�������ʿ�ֳֳ����ĸ���ǹꪣ�\n"
                                        "  ��$n�߸ߵز������棬���һ������...�� ������ʯ��������ȥ��\n" NOR, this_object(), ob);
        delete_temp("can_enterredlroom", ob);
        ob->move("/u/redl/private_room/dating");
        message_vision(YEL "$N��ʯ���Ϲ�µ��µ��������ˤ�˸��߻���أ����ڵ����޷�������\n" NOR, ob);
        ob->start_busy(30);
        return 1;
}

int do_sm(string arg)
{
        object me, ob;
        me = this_player();
        if ( !is_owner(me) ){
                tell_object(me, NOR"���޷���ʹ����Ȩ��\n"NOR);
                return 1;
        }
        if (!arg || arg=="") {
                tell_object(me, "����Ҫָ��һλ��ҡ�\n");
                return 1;
        }
        ob = find_player(arg);
        if (!ob || !objectp(ob) || !playerp(ob)) {
                tell_object(me, "��û�з���������ҡ�\n");
                return 1;
        }

        this_object()->command("remove all");
        message_vision(YEL "$N¶���ﴩ��һ�׺�ɫPU�ο����¡���ɫPU�����ȹ����ɫ��˿�������\n"
                                           "  ��Ѹ������һ��ɺ����ħ���Ǵ��ã������ų����ɫ��Ƥ�޶���$n�ٺ�һЦ����\n" NOR, this_object(), ob);
        for(int i = 16; i > 0; i--) {
                int rnd = random(7);
                switch(rnd)
                {
                        case 0:
                        case 1:
                                this_object()->command("whip " + query("id", ob));
                break;
                        case 2:
                        case 3:
                                this_object()->command("sm " + query("id", ob));
                break;
                        case 4:
                        case 5:
                                this_object()->command("candle " + query("id", ob));
                break;
                        case 6:
                                this_object()->command("kiss " + query("id", ob) + " �˿�");
                break;
        }
        }
        this_object()->command("wear all");
        this_object()->command("hoho " + query("id", ob));
        //ob->unconcious();
        return 1;
}

int do_cpat()
{
        message_vision(YEL "$n" NOR YEL "����������$N" NOR YEL "���Դ���$N" NOR YEL "������~���͵�һ�������ֻСè�䡣\n" NOR, this_object(), this_player());
        new(__DIR__"lcat")->move(environment(this_object()));
        destruct(this_object());
        return 1;
}





