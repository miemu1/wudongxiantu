// cigarette.c  by Jane  4.12.1997
// redl 2013/6
#include <ansi.h> 
inherit ITEM;

int smoking(int);

void create()
{
        string *order = ({"���", "�Ͼ�", "�ƺ�¥", "��Ⱥ", "����"});
        set_name( (order[random(5)]), ({ "cigarette" }) );
        set_weight(80);
                set("long", "һ�����̣�����(xiyan)��\n");
                set("unit", "��");
                set("count",12);
                set("value", 200000000);
                set("set_data", 1);  
                set("auto_load", 1); 
                set("no_sell", "��õ��̰����������ϧ���Ͻ������..."); 
}

void init()
{
        add_action("do_smoke", "xiyan");
}

void call_pond(object me)
{
        call_other("/u/redl/obj/cigarette_c", "chk_pond", me );
        destruct(this_object());
}

int do_smoke()
{
                int stp, lh = 4 + random(3);
        object me = this_player();
        object obj = this_object();

        if( query("no_smoke", environment(me)) && (wiz_level(me) < wiz_level("(wizard)")) )
                return notify_fail("���ﲻ׼���̣�\n");

        if( me->is_busy() ) {
                        me->command("cough");
                return 1;
        }
                
        if(query("count") == 12) 
                message_vision("$N���һ֧$n�������˻������̵�����������\n", me, this_object());
        else if (query("count") <= 1 ) {
                message_vision(YEL "$N��ʣ�µ��̵���Ϩ������������������ѽ��\n" NOR, me, obj);
                            set("no_give", "�̵�ճ�������������...");
                        set("no_store", "�̵�ճ�������������...");
                        set("no_drop", "�̵�ճ�������������...");
                        set("no_sell", "�̵�ճ�������������...");
                        set("no_steal", "�̵�ճ�������������...");
                        set("no_beg", "�̵�ճ�������������...");
                call_out("call_pond", 1, me);
                me->start_busy(3);
                return 1;
        } else 
        switch(random(12)) {
                case 0: 
                case 1: 
                                message_vision(HIK "$Nʳָ�����ö�$n���̻һ����̸������һ�ѻ�ɫ��ѩ��\n" NOR, me, obj );
                                addn("magic_points", lh, me); 
                                write(NOR + "��ϲ�������гɣ�������" + chinese_number(lh) + "����ۣ�\n" + NOR);
                        break;
                case 2: 
                                if (time()-query("last_time") < 1+random(2)) {
                                        message_vision(YEL "$N�ݺݵ�����һ��$n�����������̫���ˣ�һ�����ǵ�ͨ�졣\n" NOR, me, obj);
                                        me->start_busy(25 + random(6));
                                } else {
                                        message_vision(HIK "$N����һ̾���������ͷ�ϻ��Ǻ�����������˼Ҳ��ɬ�ѱ硣\n" NOR, me );
                                        addn("magic_points", lh*3, me); 
                                        write(NOR + "��ϲ�����������������" + chinese_number(lh*5) + "����ۣ�\n" + NOR);
                                }
                        break;
                default:
                                addn("stp", 1);
                                stp = query("stp");
                                switch(stp) {
                                        case 1: 
                                                message_vision(NOR "$N�³�һ����Ȧ����������������һ����һ����Ʈɢ��. \n" NOR, me);
                                        break;
                                        case 2: 
                                                message_vision(NOR "$N�³�һ����Ȧ����������������һ����һ����Ʈɢ��. ��\n" NOR, me);
                                        break;
                                        case 3: 
                                                message_vision(NOR "$N�³�һ����Ȧ����������������һ����һ����Ʈɢ��. ��o\n" NOR, me);
                                        break;
                                        case 4: 
                                                message_vision(NOR "$N�³�һ����Ȧ����������������һ����һ����Ʈɢ��. ��o O\n" NOR, me);
                                        break;
                                        default:
                                                message_vision(NOR "$N�������һ�����̣������о�Ĭ�ţ�����һֻ����\n" NOR, me);
                                                if (random(3)) set("stp", 0);
                                        break;
                                }
                        break;
        }
        addn("count",-1);
        set("last_time", time());
        return 1;
}



