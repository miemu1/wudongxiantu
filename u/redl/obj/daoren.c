// This program is a part of NITAN MudLIB 
// redl 2013/5/10

#include <ansi.h>
inherit ITEM;

int clean_up() { return 1;}

void create()
{
        set_name(NOR "��������" NOR, ({"dao ren"}));
                set("long",  NOR "ԭ�����Ǿ����������ʬ�ǣ��ֽ�ǧ��Ѫ��ӡ���½������Ŷ�С�컨��\n" NOR);
                set("weight", 1000000000);
                set("unit", "��");
                set("no_store", "���Ƕ����ߵĴ󲻾���\n"); 
                set("no_steal", "���Ƕ����ߵĴ󲻾���\n"); 
                set("no_beg", "���Ƕ����ߵĴ󲻾���\n"); 
                set("no_get", "���Ƕ����ߵĴ󲻾���\n"); 
                set("no_uget", "���Ƕ����ߵĴ󲻾���\n"); 
        setup();
}

void init()
{
                object me = this_player();
        if (query("redl/gethomerune", me)<3) add_action("do_action", "");
        delete_temp("has_kneelredl", this_player());
}

int do_action(string arg)
{
        string action = query_verb();
        object me = this_player();
        //tell_object(me, YEL + "id:<" + query("id",me) + "> action:<" + action + ">" + ((arg != "") ? " "+arg : "") + "\n" + NOR); 
        if (action=="look" && arg=="dao ren" && !query_temp("looked")) {
                me->start_busy(3);
                set_temp("looked", 1);
                        me->remove_call_out("do_look");
                        call_out("do_look", 2, me);
                } else if (action=="kneel" && arg=="dao ren") {
                        if(me->is_busy()) {
                                tell_object(me, NOR "��̬�ȹ�����㣬��ôҲ����ȥ��\n" NOR);
                                me->start_busy(3+ random(2));
                                return 1;
                        }
                        me->start_busy(2);
                        if (!query_temp("has_kneelredl", me)) set_temp("has_kneelredl", 0, me);
                        addn_temp("has_kneelredl", 1, me);
                        message_vision(NOR "$N��������$n" NOR "����"+chinese_number(query_temp("has_kneelredl", me))+"����ͷ��\n" NOR, me, this_object());
                        return 1;
                } // else if (arg=="dao ren") {
//                      me->command(action + " " + query("id", me));
//                      me->command(action + " " + query("id", me));
//              }
        return 0;
}

int do_look(object me)
{
        int ki = query_temp("has_kneelredl", me), i;
        delete_temp("has_kneelredl", me);
        
        if (
                !query_temp("can_enterredlroom", me) && 
                query("id", me) != "redl" && query("couple/couple_id", me) != "redl" && 
                (query("get_time", environment())>time() - 5400) 
                ) {
                        message_vision(YEL "��$N����Ŀע���£�$n" YEL "���ź�˲�������ɳ�������Ʈɢ��������ȥ�ˡ�\n" NOR, me, this_object());
                        destruct(this_object());
                        return 1;
                }
        
        if (ki > 10) ki = 10;
        
        message_vision(YEL "��$N����Ŀע���£�$n" YEL "���ź�˲�������ɳ�������Ʈɢ��������ȥ�ˡ�\n" NOR, me, this_object());

        if (!query_temp("has_getrune", me) && !random(5)) 
                if (ki > 2) {
                set_temp("has_getrune", 1, me);
                i = (11 - ki);
                for(int i2 = i; i2 > 0; i2--) { new("/clone/tessera/rune" + to_string(20 + ki))->move(me);      }
                tell_object(me, HIG "��о���������˵㶫������æ����һ����ԭ����" + chinese_number(i) + "������(rune" + to_string(20 + ki) + ")��\n" NOR);
                addn("redl/gethomerune", 1, me);
                if (query("redl/gethomerune", me)>2)
                        tell_object(me, YEL "������ԼԼ����һ�����������Ժ������𣺲�Ҫ�ٻ����ˣ����ɶ���˵������ͽ�ܡ�\n" NOR);
        }
        
        if (!random(4)) new(__DIR__"mbox")->move(environment());
        set("get_time", time(), environment());
        destruct(this_object());
        return 1;
}



