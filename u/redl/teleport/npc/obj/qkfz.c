// This program is a part of NITAN MudLIB 
// redl 2015/10
// ��ɽ������
inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(NOR CYN "Ǭ��"YEL"����"NOR, ({"qiankun fuzhao", "fu", "fuzhao"}));
        set("long",
                "���������صķ�ֽ��ʹ��(use �������)���Գ�ȡ�����Ķ��ֵĻ��ǣ���Ϊ����Ǭ��������Ĳ�衣\n");
        set("unit", "��");
        set("weight", 10);
        set("value", 100000000);
}

int random2 (int i)
{
        return (random(i)+uptime()) % i;
}

int rdm(object me, object target, int step)
{
        object p1, p2;
        object room = environment(me);
        int lv1, lv2;
        
        if (step && me && target) {
                if (step==1) {
                        p1 = me;
                        p2 = target;
                } else if (step==2) {
                        p1 = target;
                        p2 = me;
                } else if (step==3) {
                        p1 = me;
                        p2 = target;
                } else if (step==4) {
                        p1 = target;
                        p2 = me;
                } 
                
                if (step==1 || step==2) {
                        lv1 = p1->query_skillo("du-sheng", 1);
                        lv2 = p2->query_skillo("du-sheng", 1);
                        if (lv1 && !random(4)) {
                                tell_room(room, NOR + CYN + query("name", p1) + NOR + CYN + "�������ð��������Ц��\nȻ�������³����������ġ�����������\n" + NOR);
                                if (random(lv2*3) > lv1) {
                                        tell_room(room, NOR + CYN + query("name", p2) + NOR + CYN + "��ʳָ����˫̫��Ѩ���͵������۾�����" + query("name", p1) + NOR + CYN + "һ����\n" + NOR);
                                        tell_room(room, NOR + CYN + query("name", p1) + NOR + CYN + "�۵�ӿ��һ����Ѫ����ǿ�����������˻�ȥ��\n" + NOR);
                                        return random2(6);
                                } else {
                                        tell_room(room, NOR + CYN + query("name", p1) + NOR + CYN + "������Ц����������������ʥ����\n" + NOR);
                                        return 6;
                                }
                        }
                } else if (step==3 || step==4) {
                        lv1 = p1->query_skillo("du-shen", 1);
                        lv2 = p2->query_skillo("du-shen", 1);
                        if (lv1 && !random(5)) {
                                tell_room(room, NOR + CYN + query("name", p1) + NOR + CYN + "���еؽ����ɿ�����\n��ָ�ϵĽ�ָȴ͵͵��������һ��...\n" + NOR);
                                if (random(lv2*3) > lv1) {
                                        tell_room(room, NOR + CYN + query("name", p2) + NOR + CYN + "����ü�������������ŵĴ�ѩ�ѣ���" + query("name", p1) + NOR + CYN + "����һ�硣\n" + NOR);
                                        tell_room(room, NOR + CYN + query("name", p1) + NOR + CYN + "��Ǻ�ÿ��Բ�ֹ������ָ��" + query("name", p2) + NOR + CYN + "�����㡫��\n" + NOR);
                                        return random2(6);
                                } else {
                                        tell_room(room, NOR + CYN + query("name", p1) + NOR + CYN + "����¶������һ��������΢Ц��\n" + NOR);
                                        if (step==3) return query("a_n1");
                                        if (step==4) return query("b_n1");
                                }
                        }
                }
        }
        
        return random2(6) + 1;
}

void display_bet(int i, int j)
{
        string str;
        object room = environment();
        switch (i)
        {
        case 1:
                str = ((j) ? RED : HIW) + 
"����������\n"+
"����������\n"+
"�����񡡩�\n"+
"����������\n"+
"����������\n" + NOR;
                break;
        case 2:
                str = ((j) ? RED : HIW) + 
"����������\n"+
"����������\n"+
"���񡡡�\n"+
"����������\n"+
"����������\n" + NOR;
                break;
        case 3:
                str = ((j) ? RED : HIW) + 
"����������\n"+
"���񡡡���\n"+
"�����񡡩�\n"+
"��������\n"+
"����������\n" + NOR;
                break;
        case 4:
                str = ((j) ? RED : HIW) + 
"����������\n"+
"���񡡡�\n"+
"����������\n"+
"���񡡡�\n"+
"����������\n" + NOR;
                break;
        case 5:
                str = ((j) ? RED : HIW) + 
"����������\n"+
"���񡡡�\n"+
"�����񡡩�\n"+
"���񡡡�\n"+
"����������\n" + NOR;
                break;
        case 6:
                str = ((j) ? RED : HIW) + 
"����������\n"+
"���񡡡�\n"+
"���񡡡�\n"+
"���񡡡�\n"+
"����������\n" + NOR;
                break;
        }
        tell_room(room,str + "(" + (string)i + ")��\n" + NOR);
}

int do_start_bet(object me, object target, int step)
{
                string jgmsg1, jgmsg2;
                int sklv1, sklv2, iaccept, itmp;
                float eff, efftmp;
        if (!me || !target) return 0;
        if (!environment(me) || !environment(target)) return 0;
        if (environment(me) != environment(target)) return 0;
        me->start_busy(2);
        target->start_busy(2);
        switch(step)
        {
                case 0:
                        set_temp("flag_bet", 1);
                                        message_vision(NOR "$N��������$n��ɸҽ��´˷���\n" NOR, me, target);
                                        sklv1 = target->query_skillo("du-sheng", 1);
                                        sklv2 = target->query_skillo("du-shen", 1);
                                        eff = 1.00;
                                        efftmp = to_float(query("qi", target)) / to_float(query("max_qi", target));
                                        if (efftmp < eff) eff = efftmp;
                                        efftmp = to_float(query("eff_qi", target)) / to_float(query("max_qi", target));
                                        if (efftmp < eff) eff = efftmp;
                                        efftmp = to_float(query("jing", target)) / to_float(query("max_jing", target));
                                        if (efftmp < eff) eff = efftmp;
                                        efftmp = to_float(query("eff_jing", target)) / to_float(query("max_jing", target));
                                        if (efftmp < eff) eff = efftmp;
                                        iaccept = random(to_int(eff * 100)) + to_int(eff * 100)/10 - sklv1/10 - sklv2/5;
                                        //DEBUG_CHANNEL("iaccept:" + (string)iaccept + "\n");
                                        if ( iaccept < 15 ) {
                                                if (eff < 0.4) 
                                                        message_vision(NOR "$N��ϲ��������������ȡ��һ��������\n" NOR, target);
                                                else
                                                        message_vision(NOR "$N��Ҳ����˵�������кβ��ң�\n" NOR, target);
                                        } else {
                                                message_vision(NOR "$nһ�ѳ���" + name() + NOR "����û��$N�����ơ�\n" NOR, me, target);
                                                delete_temp("flag_bet");
                                                return 0;
                                        }
                    break;
                case 1:
                        tell_room(environment(), RED + me->name() + NOR + "����һ�ӣ����ӵ�����һת��\n");
                        display_bet(itmp = rdm( me,  target,  step), 1);
                        set("a_n1", itmp);
                                                break;
                case 2:
                        tell_room(environment(), HIW + target->name() + NOR + "����һ�ӣ����ӵ�����һת��\n");
                        display_bet(itmp = rdm( me,  target,  step), 0);
                        set("b_n1", itmp);
                                                break;
                case 3:
                        tell_room(environment(), RED + me->name() + NOR + "�������ӹ��˿������ݺݵ�һ�ӣ�\n");
                        display_bet(itmp = rdm( me,  target,  step), 1);
                        set("a_n2", itmp);
                                                break;
                case 4:
                        tell_room(environment(), HIW + target->name() + NOR + "�������ӹ��˿������ݺݵ�һ�ӣ�\n");
                        display_bet(itmp = rdm( me,  target,  step), 0);
                        set("b_n2", itmp);
                                                break;
                                default:
                                if (query("a_n1") == query("a_n2")) {
                                        jgmsg1 = "\"" + "һ��" + chinese_number(query("a_n1")) + "\"";
                                        set("a_n1", (query("a_n1") + query("a_n2")) * 100);
                                }
                                else {
                                        set("a_n1", query("a_n1") + query("a_n2"));
                                                                                jgmsg1 = "\"" + chinese_number(query("a_n1")) + "��" + "\"";
                                }
                                        
                                if (query("b_n1") == query("b_n2")) {
                                        jgmsg2 = "\"" + "һ��" + chinese_number(query("b_n1")) + "\"";
                                        set("b_n1", (query("b_n1") + query("b_n2")) * 100);
                                }
                                else  {
                                        set("b_n1", query("b_n1") + query("b_n2"));
                                        jgmsg2 = "\"" + chinese_number(query("b_n1")) + "��" + "\"";
                                }

                                if (query("a_n1") > query("b_n1")) {
                                        message_vision(NOR + name() + "��һ������ʾ��" + jgmsg1 + "����" + jgmsg2 + "��" +  "$N" + NOR + "��ʤ��\n" + NOR, me);
                                        return 1;
                                } else if (query("a_n1") < query("b_n1")) {
                                        message_vision(NOR + name() + "��һ������ʾ��" + jgmsg2 + "����" + jgmsg1 + "��" +  "$N" + NOR + "��ʤ��\n" + NOR, target);
                                } else {
                                        message_vision(NOR + name() + "��һ������ʾ��" + jgmsg1 + "����" + jgmsg2 + "��" +  "$N" NOR "��$n" + NOR + "ƽ�֡�\n" + NOR, me, target);
                                }
                                return 0;
                }
        step += 1;
        return do_start_bet(me, target, step);
}

int do_use(string arg)
{
        int i, need;
        object *enemies, enemy;
        object chong, me = this_player();
        if (!environment() || environment()!=me) return 0;
        if (!arg) return notify_fail("����Ϊ����1-9��\n");
        if (strlen(arg)!=1) return notify_fail("����Ϊ����1-9��\n");
        if (arg[0] < '1' || arg[0] > '9') return notify_fail("����Ϊ����1-9��\n");
        if (me->is_busy()) {
                write (NOR BUSY_MESSAGE NOR);
                return 1;
        }
        if (!me->is_fighting()) {
                write (NOR "�������ս�������ʹ�á�" NOR);
                return 1;
        }
        me->start_busy(1);
        i = to_int(arg);
        need = i*i*i/2 + 1;//����9����Ҫ365ö���ӣ�Լ18���䶯��;��
/*����Ϊ����1-9��
���Ǭ������������������֧����ô����(��Ҫ1ö����)��
���Ǭ������������������֧����ô����(��Ҫ5ö����)��
���Ǭ������������������֧����ô����(��Ҫ14ö����)��
���Ǭ������������������֧����ô����(��Ҫ33ö����)��
���Ǭ������������������֧����ô����(��Ҫ63ö����)��
���Ǭ������������������֧����ô����(��Ҫ109ö����)��
���Ǭ������������������֧����ô����(��Ҫ172ö����)��
���Ǭ������������������֧����ô����(��Ҫ257ö����)��
���Ǭ������������������֧����ô����(��Ҫ365ö����)��*/
        if ( need > query("qiankunqipan/limit_guest", me)) {
                write(NOR "���Ǭ������������������֧����ô����(��Ҫ"+(string)need+"ö����)��\n" NOR); 
                return 1;
        }
        enemies = me->query_enemy();
        if( !enemies || sizeof(enemies) < 1 ) {
                write (NOR "��Ŀǰû�е��ˡ�" NOR);
                return 1;
        }
        enemy = enemies[random(sizeof(enemies))];
        if (!enemy) {
                write (NOR "��Ŀǰû�е��ˡ�" NOR);
                return 1;
        }
        if (!enemy->is_character() || !query("can_speak", enemy)) {
                write (NOR "��û����" + enemy->name() + NOR "ǩ�������Լ��" NOR);
                return 1;
        }
        if (query_temp("is_qkfz", enemy)) {
                write (NOR + enemy->name() + NOR "�Ѿ�ǩ���������Լ��" NOR);
                return 1;
        }       
        if (playerp(enemy) && !query_temp("in_pkd", enemy)) {
                write (NOR + "ֻ�������˳����ܱ����Լ��" NOR);
                return 1;
        }       
        message_vision(NOR YEL "$N" NOR YEL  "���ּ���һ��" + name() + NOR YEL "Ʈ��ȥ�����á�pia ~��������$n" NOR YEL  "�Ķ�ͷ�ϡ�\n" NOR, me, enemy);
        if (do_start_bet(me, enemy, 0)) {
                message_vision(NOR YEL "$N" NOR YEL  "������$n" NOR YEL  "��һ����ǡ�\n" NOR, me, enemy);
                set_temp("is_qkfz", 1, enemy);
                chong = new("/u/redl/teleport/npc/chachong");
                chong->do_copy(enemy, me, i);
                destruct(chong);
                enemy->die(me);
        }
        else {
                message_vision(NOR YEL "$N" NOR YEL  "��Լ$n" NOR YEL  "��Ȼʧ�ܡ�\n" NOR, me, enemy);
                if (query_temp("flag_bet")) {
                        set_temp("die_reason", NOR + "��Լ"+enemy->name()+"ʧ�ܶ���" + NOR, me);
                        me->die(enemy);//ƽ���㷢��������
                }
        }
        destruct(this_object());
        //write("ok\n");
        return 1; 
}


void init()
{
        object me = this_player();
        if (playerp(me)) {
                add_action("do_use", "use");
        }
}


