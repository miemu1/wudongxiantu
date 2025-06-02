// This program is a part of NITAN MudLIB 
// redl 2015/10
#include <ansi.h>
inherit ITEM;

void create() 
{ 
              set_name(NOR HIB "����"NOR, ({"trap A"}) ); 
                        set_weight(100000000000);
                set("long", NOR "���ǽ�������壬���˷���ʤ����ͷ�۲��ѡ�\n" NOR);
                set("unit", "��");
                set("value", 1);
                set("no_uget", 1);
                set("no_drop", 1);
                set("no_give", 1);
                set("no_sell", 1);
                set("no_get", 1);
                set("no_steal", 1);
                set("no_beg", 1);
                set("no_put", 1);
                set("no_store", 1);
                set("unique", 1);
                set("no_pawn", 1);
              setup(); 
} 

void do_trap1(object me)
{
        int dmg = 300000 + random(100000);
        if (!environment(me) || environment(me)!=environment(this_object()))    return;
        message_vision( NOR + HIB ".����." HIK "�Ե�һ����һ��ţëϸ������$N��������Ѫ��ֹ��\n" NOR, me);
        me->receive_damage("qi",dmg,this_object());
        me->receive_wound("qi",dmg/2,this_object());
        COMBAT_D->report_status(me);
        if( !me->is_busy() ) me->start_busy(random(4)+1);
        call_out("do_trap1", random(3) + 1, me);
}
void do_trap2(object me)
{
        int dmg = 150000 + random(50000);
        if (!environment(me) || environment(me)!=environment(this_object()))    return;
        message_vision( NOR + HIB ".����." HIK "�Ե�һ����һ��̱���ζѬ��$N�ڱ���Ż��\n" NOR, me);
        me->receive_damage("jing",dmg,this_object());
        me->receive_wound("jing",dmg/2,this_object());
        COMBAT_D->report_status(me);
        if( !me->is_busy() ) me->start_busy(random(4)+1);
        call_out("do_trap2", random(3) + 1, me);
}
void do_trap3(object me)
{
        int dmg = 150000 + random(50000);
        if (!environment(me) || environment(me)!=environment(this_object()))    return;
        message_vision( NOR + HIB ".����." HIK "�Ե�һ�����ذ������һ����ǩ�̴���$N�Ľ��ơ�\n" NOR, me);
        if( !me->is_busy() ) me->start_busy(random(6)+12);
        call_out("do_trap3", random(36) + 1, me);
}
void do_trap4(object me)
{
        int dmg = 150000 + random(50000);
        if (!environment(me) || environment(me)!=environment(this_object()))    return;
        message_vision( NOR + HIB ".����." HIK "�Ե�һ����ǽ��һ���������һ����˪����$N����������\n" NOR, me);
        me->set_freeze(45, 0);
        if( !me->is_busy() ) me->start_busy(random(4)+1);
        call_out("do_trap4", random(3) + 1, me);
}

void init()
{
        object me = this_player();
        if (!playerp(me)) return;
                switch(random(4)) {
                        case 0:
                                do_trap1(me);
                                break;
                        case 1:
                                do_trap2(me);
                                break;
                        case 2:
                                do_trap3(me);
                                break;
                        case 3:
                                do_trap4(me);
                                break;
                }
}


