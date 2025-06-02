// This program is a part of NITAN MudLIB 
// redl 2013/8
// 5%�����ʥͬʱ����

#include <ansi.h>
#define CHANL_NAME "auc"
#define CHARM_BASEFILE "/clone/goods/tianshi-charm"
#define DEBUG 0
#define BET_ME 1        //���Ҳ����ţ��ͷ�û�м���á��������ղ��Ѻ�

inherit NPC;

int a_amount = 0, a_n1, a_n2, b_n1, b_n2, itmp, slv, sexp, spot, smar, sper;
string a_file, a_id, b_id, a_name, b_name, ob_name;
object usra, usrb;

void imp_sk(object me)
{
        if (!random(5)) {
                if (!random(3)) {
                        if (me->query_skillo("du-shen", 1) < 1000) me->improve_skill("du-shen", 200 + 2 * query("level", me)); 
                } else {
                        if (me->query_skillo("du-sheng", 1) < 1000) me->improve_skill("du-sheng", 200 + 2 * query("level", me)); 
                }
        }
}

int query_ln(object me)
{
        int tim = query("yangyong/learn/time", me);
        int num = query("yangyong/learn/num", me);
        
        if (undefinedp(tim) || !tim || tim!=time() / 86400) {
                tim = time() / 86400;
                num = 0;
                set("yangyong/learn/time", tim, me);
                set("yangyong/learn/num", num, me);
        }
        return num;
}

void add_ln(object me)
{
        addn("yangyong/learn/num", 1, me);
        tell_object(me, NOR + "�����Ĳ�" + chinese_number(query("yangyong/learn/num", me)) + "���ˡ�\n" + NOR);
}

int random2 (int i)
{
        return (random(i)+uptime()) % i;
}

int rdm()
{
        object me, ene;
        object room = environment();
        int lv1, lv2, stp = query("stp_current");
        
        if (stp && usra && usrb) {
                if (stp==1) {
                        me = usra;
                        ene = usrb;
                } else if (stp==2) {
                        me = usrb;
                        ene = usra;
                } else if (stp==3) {
                        me = usra;
                        ene = usrb;
                } else if (stp==4) {
                        me = usrb;
                        ene = usra;
                } 
                
                if (stp==1 || stp==2) {
                        lv1 = me->query_skillo("du-sheng", 1);
                        lv2 = ene->query_skillo("du-sheng", 1);
                        if (lv1 && !random(4)) {
                                tell_room(room, NOR + CYN + query("name", me) + NOR + CYN + "�������ð��������Ц��\nȻ�������³����������ġ�����������\n" + NOR);
                                if (random(lv2*3) > lv1) {
                                        tell_room(room, NOR + CYN + query("name", ene) + NOR + CYN + "��ʳָ����˫̫��Ѩ���͵������۾�����" + query("name", me) + NOR + CYN + "һ����\n" + NOR);
                                        tell_room(room, NOR + CYN + query("name", me) + NOR + CYN + "�۵�ӿ��һ����Ѫ����ǿ�����������˻�ȥ��\n" + NOR);
                                        return random2(6);
                                } else {
                                        tell_room(room, NOR + CYN + query("name", me) + NOR + CYN + "������Ц����������������ʥ����\n" + NOR);
                                        return 6;
                                }
                        }
                } else if (stp==3 || stp==4) {
                        lv1 = me->query_skillo("du-shen", 1);
                        lv2 = ene->query_skillo("du-shen", 1);
                        if (lv1 && !random(5)) {
                                tell_room(room, NOR + CYN + query("name", me) + NOR + CYN + "���еؽ����ɿ�����\n��ָ�ϵĽ�ָȴ͵͵��������һ��...\n" + NOR);
                                if (random(lv2*3) > lv1) {
                                        tell_room(room, NOR + CYN + query("name", ene) + NOR + CYN + "����ü�������������ŵĴ�ѩ�ѣ���" + query("name", me) + NOR + CYN + "����һ�硣\n" + NOR);
                                        tell_room(room, NOR + CYN + query("name", me) + NOR + CYN + "��Ǻ�ÿ��Բ�ֹ������ָ��" + query("name", ene) + NOR + CYN + "�����㡫��\n" + NOR);
                                        return random2(6);
                                } else {
                                        tell_room(room, NOR + CYN + query("name", me) + NOR + CYN + "����¶������һ��������΢Ц��\n" + NOR);
                                        if (stp==3) return a_n1;
                                        if (stp==4) return b_n1;
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

void do_return()
{
        object objb, pobj;
        
        remove_call_out("do_return");
        if (a_id && b_id)
        {
                if (a_id!="" && b_id!="" && a_file!="me") return;
        }
        
        if (a_file=="me") {
            pobj = find_player(a_id);
                if (pobj)
                {
                                pobj->stop_busy();
               
                                        set_temp("yangyong/time_start", time() - 20, pobj);
                }
                message_vision("$N���ͷ���˵��" + a_name + "���������ӹ�ȥ��Ҳû�����ģ�����ε�С�����Ǳ�ס�ˡ�\n", this_object(), pobj);
        }
        else {
                objb = new(a_file);
            pobj = find_player(a_id);
                itmp = objb->query_amount();
                if (pobj)
                {
                                pobj->stop_busy();
                        if( !itmp )
                        {
                        objb->move(pobj);
                        }
                        else
                        {
                        objb->set_amount(a_amount);
                        objb->move(pobj);
                        }
                
                                        set_temp("yangyong/time_start", time() - 20, pobj);
                }
                message_vision("$N���ͷ���˵��" + a_name + "���������ӹ�ȥ��Ҳû�����ģ�" + ob_name + NOR + "�����㡣\n", this_object(), pobj);
        }
        
        log_file("static/yangyong", sprintf("  -%s(%s)������˻���\n",  a_name, a_id));
        a_amount = 0;
        a_id = b_id = "";
}

void do_end(string id)
{
        object objb, pobj;

        remove_call_out("do_return");
        objb = new(a_file);
        pobj = find_player(id);
        itmp = objb->query_amount();
        if (pobj)
        {
                if( !itmp )
                {
                        objb->move(pobj);
                        new(a_file)->move(pobj);
                }
                else
                {
                        objb->set_amount(a_amount * 2);
                        objb->move(pobj);
                }
        }
}

void do_kill(object target, object me)
{
        mapping ob; 
        object *obs;
        int icharm = 0;
        
        //��ʱ�Ƴ����е���ʦ��
        obs = all_inventory(target); 
                if (sizeof(obs) > 0) 
                { 
                        obs = obs[0..<1]; 
                        foreach (ob in obs) {
                                if (base_name(ob)==CHARM_BASEFILE) {
                                        destruct(ob); 
                                        icharm += 1;
                                }
                        }
                } 
        
        for(int i = a_amount; i > 0; i--) {     
                set_temp("die_reason", "��Ϊ�������" + query("name",me) + "����", target);
                target->die();
                target->reincarnate();
                target->move(environment(me));
                addn("combat_exp", sexp, me);
                addn("potential", spot, me);
                addn("experience", smar, me);
                CHANNEL_D->channel_broadcast(CHANL_NAME, NOR + query("name", me) + NOR + "��" + query("name", target) + NOR + "��ʬ���ϻ����" + 
                        "��Ϊ:" + sexp + "��" + 
                        "Ǳ��:" + spot + "��" + 
                        "���:" + smar + "��\n" + NOR);
                log_file("static/yangyong", sprintf("  -��Ϊ%d��Ǳ��%d�����%d��\n",  sexp, spot, smar));
                sexp /= 2;
                spot /= 2;
                smar /= 2;
        }
        
        for(int j = icharm; j > 0; j--) {       
                new(CHARM_BASEFILE)->move(target);
        }       
}

int do_start(int step)
{
        string jgmsg1, jgmsg2;
        usra->start_busy(999);
        usrb->start_busy(999);
        remove_call_out("do_start");
        switch(step)
        {
                case 0:
                                message_vision("$N�����������������ڿ�ʼ��\n", this_object());
                                                                if (a_file=="me") {
                                                                        sper = 20;//������������֮�ͣ�����20�������´���ι������Ϊ�޷���֤��id��һ����Ӯ
                                                                        slv = abs((query("level",usra)) - (query("level",usrb)));//˫���ĵȼ��Խ����Խ��
                                                                        if (DEBUG) CHANNEL_D->channel_broadcast("wiz", NOR + "�ȼ���:" + slv + "\n" + NOR);
                                                                        if ( (query("level",usra) / 10) < slv || (query("level",usrb) / 10) < slv ) sper *= 2;//�ٳ���2
                                                                        if ( (query("level",usra) / 5) < slv || (query("level",usrb) / 5) < slv ) sper *= 2;//�ٳ���2
                                                                        if ( (query("level",usra) / 2) < slv || (query("level",usrb) / 2) < slv ) sper *= 128;
                                                                        sexp = (query("combat_exp",usra));
                                                        spot = (query("potential", usra)-query("learned_points", usra));
                                                        smar = (query("experience", usra)-query("learned_experience", usra));
                                                                        sexp += (query("combat_exp",usrb));
                                                        spot += (query("potential", usrb)-query("learned_points", usrb));
                                                        smar += (query("experience", usrb)-query("learned_experience", usrb));
                                                        sexp /= sper;
                                                        spot /= sper;
                                                        smar /= sper;
                                                                        if (DEBUG) CHANNEL_D->channel_broadcast("wiz", NOR + "��������:1/" + sper + "  ��Ϊ:" + sexp +  "  Ǳ��:" + spot +  "  ���:" + smar + "\n" + NOR);
                                                                }
                                break;
                case 1:
                        tell_room(environment(), RED + a_name + NOR + "����һ�ӣ����ӵ�����һת��\n");
                        set("stp_current", 1);
                        display_bet(a_n1 = rdm(), 1);
                                break;
                case 2:
                        tell_room(environment(), HIW + b_name + NOR + "����һ�ӣ����ӵ�����һת��\n");
                        set("stp_current", 2);
                        display_bet(b_n1 = rdm(), 0);
                                break;
                case 3:
                        tell_room(environment(), RED + a_name + NOR + "�������ӹ��˿������ݺݵ�һ�ӣ�\n");
                        set("stp_current", 3);
                        display_bet(a_n2 = rdm(), 1);
                                break;
                case 4:
                        tell_room(environment(), HIW + b_name + NOR + "�������ӹ��˿������ݺݵ�һ�ӣ�\n");
                        set("stp_current", 4);
                        display_bet(b_n2 = rdm(), 0);
                                break;
                                default:
                                if (a_n1 == a_n2) {
                                        jgmsg1 = "һ��" + chinese_number(a_n1);
                                        a_n1 = (a_n1 + a_n2) * 100;
                                }
                                else {
                                        a_n1 = a_n1 + a_n2;
                                                                             jgmsg1 = chinese_number(a_n1) + "���";
                                }
                                        
                                if (b_n1 == b_n2) {
                                        jgmsg2 = "һ��" + chinese_number(b_n1);
                                        b_n1 = (b_n1 + b_n2) * 100;
                                }
                                else  {
                                        b_n1 = b_n1 + b_n2;
                                        jgmsg2 = chinese_number(b_n1) + "���";
                                }

                                if (a_n1 > b_n1) {
                                        message_vision("$N������" + jgmsg1 + "��" + RED + a_name + NOR + "��ʤ��\n" + NOR, this_object());
                                        log_file("static/yangyong", sprintf("  -%s(%s)ʤ����\n",  a_name, a_id));
                                        if (a_file=="me") {
                                                do_kill(usrb, usra);
                                        } 
                                        else {
                                                do_end(a_id);
                                                message_vision("$N�ó�һЩ" + ob_name + NOR + "����" + a_name + "��\n" + NOR, this_object());
                                                CHANNEL_D->channel_broadcast(CHANL_NAME, query("name") + NOR + "�ó�һЩ" + ob_name + NOR + "������ʤ��" + a_name + "��\n" + NOR);
                                        }
                                        if (usra) imp_sk(usra);
                                } else if (a_n1 < b_n1) {
                                        message_vision("$N������" + jgmsg2 + "��" + HIW + b_name + NOR + "��ʤ��\n" + NOR, this_object());
                                        log_file("static/yangyong", sprintf("  -%s(%s)ʤ����\n",  b_name, b_id));
                                        if (a_file=="me") {
                                                do_kill(usra, usrb);
                                        } 
                                        else {
                                                do_end(b_id);
                                            message_vision("$N�ó�һЩ" + ob_name + NOR + "����" + b_name + "��\n" + NOR, this_object());
                                                CHANNEL_D->channel_broadcast(CHANL_NAME, query("name") + NOR + "�ó�һЩ" + ob_name + NOR + "������ʤ��" + b_name + "��\n" + NOR);
                                            }
                                        if (usrb) imp_sk(usrb);
                                } else {
                                        message_vision("$N��������ƽ�֣����������ӡ�\n", this_object());
                                        step = 0;
                                        break;
                                }
                                        
                                a_amount = 0;
                                a_id = b_id = "";
                                set_temp("yangyong/time_start", time(), usra);
                                set_temp("yangyong/time_start", time(), usrb);
                                                        usra->stop_busy();
                                                        usrb->stop_busy();
                                add_ln(usra);                        
                                add_ln(usrb);
                                return 1;
                }
        step += 1;
        call_out("do_start", 2, step);
        return 1;
}

int do_accept()
{
        object ob, me = this_player();
        if (a_file!="me") {
                return 0;
        }
        if (a_id != query("id", me)) {
                write("��ֶĲ���������£�\n");
                return 1;
        }
        ob = find_player(b_id);
        if (!ob || !userp(ob))  {
                write("�����Ѿ�������Ϸ���ˣ�\n");
                return 1;
        }
        if (environment(ob) != environment(me)) {
                write("�ö���������������ˣ�\n");
                return 1;
        }
        ob->start_busy(999);
        me->command("nod " +  b_id + " �ðɣ�������һ�Ρ�");
        
                //����һ�¹���
                CHANNEL_D->channel_broadcast(CHANL_NAME, NOR + b_name + NOR + "Ѻ��" + RED + chinese_number(a_amount) + "����" + NOR + "���㡣\n" + HIB
                        + "  - �ȼ���" + (query("level",ob)) + "\n"
                        + "  - ��Ϊ��" + (query("combat_exp",ob)) + "\n"
                        + "  - Ǳ�ܣ�" + (query("potential", ob)-query("learned_points", ob)) + "\n"
                        + "  - ��᣺" + (query("experience", ob)-query("learned_experience", ob)) + "\n"
                        + NOR);
                                log_file("static/yangyong", sprintf("  -%s(%s)���㣬�ȼ�%d����Ϊ%d��Ǳ��%d�����%d��\n",  b_name, b_id, (query("level",ob)), (query("combat_exp",ob)), (query("potential", ob)-query("learned_points", ob)), (query("experience", ob)-query("learned_experience", ob)))); 

                                set("yangyong/time_start", time());
                                remove_call_out("do_return");
                call_out("do_start", 3, 0);

        return 1;       
}

int do_no()
{
        object me = this_player();
        if (a_file!="me") {
                return 0;
        }
        if (a_id != query("id", me)) {
                write("��ֶĲ���������£�\n");
                return 1;
        }
        if (!b_id) {
                write("û���������Ĳ�ѽ��\n");
                return 1;
        }
        me->command("shake �Ҷ���û��Ȥѽ");
        b_id = "";
        
        return 1;
}

int do_bet(string arg)
{
        object me;
        object ob;
        object nob;
        object *inv;
        string my_id, units;
        int amount;
        int value;
        int res;
        int max_count;
        int i;
        mixed ns;

        if( !arg ) {
                return notify_fail("��Ҫ��ʲô��\n");
        }
        
                if ((time() - query("yangyong/time_start")) < 30) 
        {
                write(CYN + name() + "���ͷ��������Ȼ������æ���ء���\n" NOR);
                return 1;
        }

        me = this_player();
       
        if(!interactive(me) || !playerp(me) || me->is_busy()) {
                return notify_fail("����æ���ء�\n");
        }
        
        if (query_ln(me)>=30) {
                write(CYN + name() + "���ߵ���������춼ѹ�������˻�������һ��İɡ���\n" NOR);
                return 1;
        }
        
        if (query("online_time", me) < 43200) {
                write(CYN + name() + "���ͷ���������Ŷ���ѽ��ë��û����Ҳ����ƶĶ�����\n" NOR);
                return 1;
        }
                
                if ((time() - query_temp("yangyong/time_start", me)) < 35) 
        {
                write(CYN + name() + "���ͷ��������Ȼ������ŸնĹ��ɣ���\n" NOR);
                return 1;
        }

                if (a_id && b_id) {
                        if (a_id!="" && b_id!="") {
                                write(CYN + name() + "˵�������ٵ�һ�Ȱɣ����������������ء���\n" NOR);
                            return 1;
                        }
                }
       
        if( sscanf(arg, "%d %s", amount, arg) != 2 )
                // not indicate the amount of the goods
                amount = 1;

        if( amount < 1 )
        {
                write(CYN + name() + "�ɻ���ʵ�����û�������ֶķ����㵽����ļ����أ���\n" NOR);
                return 1;
        }


        if (arg == "me") {//����
                
                if (!BET_ME)
                {
                write(CYN + name() + "��ü����������ʱ�����š���\n" NOR);
                return 1;
                }

        if( amount > 10 )
        {
                write(CYN + name() + "��ʧɫ����������Ҳ̫���˰ɣ����������֧�ֶ�ʮ��������\n" NOR);
                return 1;
        }
       
        if (a_amount) {

                        if (query("id", me)==a_id) {
                                write(CYN + name() + "��Ц�������Լ����Լ�ƴ�������ǰ׳հɣ���\n" NOR);
                                return 1;
                        }
                        
                        if (a_file!="me") {
                                write(CYN + name() + "���ᶼЦ������˵�����ҿ�" + a_name + "�ƺ������������������\n" NOR);
                                return 1;
                        }

                        if (amount!=a_amount) {
                                write(CYN + name() + "��Ц��˵������ô��Ѻ��������Ŀ��" + a_name + "�Ĳ�һ�°�����\n" NOR);
                                return 1;
                        }

                        message_vision("$N��ݺݵش���������㣬" + a_name + "��Ҵ�Ӧ(accept)�𣿡�\n",
                                       me, this_object());

                b_id = query("id", me);
                usrb = me;
                b_name = query("name", me);
                set_temp("yangyong/time_start", time() + 25, me);

                                tell_object(find_player(a_id), HIG + name() + HIG +  "͵͵�����㣺" + b_name + HIG + "���鱨... \n" + HIB
                        + "  - �ȼ���" + (query("level",me)) + "\n"
                        + "  - ��Ϊ��" + (query("combat_exp",me)) + "\n"
                        + "  - Ǳ�ܣ�" + (query("potential", me)-query("learned_points", me)) + "\n"
                        + "  - ��᣺" + (query("experience", me)-query("learned_experience", me)) + "\n" + HIG
                        + "�������Ŀ�������(no)��\n"
                        + NOR);
               
        } else {

                        message_vision("$N������$n˵������ҪѺ���Լ���" + chinese_number(amount) + "������\n",
                                       me, this_object());
                                                                       
                a_id = query("id", me);
                usra = me;
                a_name = query("name", me);
                a_amount = amount;
                a_file = "me";
                write(CYN + name() + "����˵�������ں���Ѿ�û���ˣ����ĵȺ����ɡ���\n" NOR);
                me->start_busy(999);
                call_out("do_return", 120);
                //����һ�¹���
                CHANNEL_D->channel_broadcast(CHANL_NAME, NOR + a_name + NOR + "Ѻ��" + RED + chinese_number(a_amount) + "����" + NOR + "�����µĶĵ��ϵȴ���ս��\n" + HIB
                        + "  - �ȼ���" + (query("level",me)) + "\n"
                        + "  - ��Ϊ��" + (query("combat_exp",me)) + "\n"
                        + "  - Ǳ�ܣ�" + (query("potential", me)-query("learned_points", me)) + "\n"
                        + "  - ��᣺" + (query("experience", me)-query("learned_experience", me)) + "\n"
                        + NOR);
                                log_file("static/yangyong", sprintf("(%s)%s(%s)������Ѻ��%d�������ȼ�%d����Ϊ%d��Ǳ��%d�����%d��\n",  ctime(time()), a_name, a_id, a_amount, (query("level",me)), (query("combat_exp",me)), (query("potential", me)-query("learned_points", me)), (query("experience", me)-query("learned_experience", me)))); 

        }
                
                return 1;
        }
        
        ob = present(arg, me);
        if( !ob )
        {
                inv = all_inventory(me);
                for( i = 0; i < sizeof(inv); i++ )
                {
                        if( filter_color(inv[i]->name(1)) == arg )
                        {
                                ob = inv[i];
                                break;
                        }
                }
        }

        if ( !objectp(ob) )
        {
                write("������û�����ֶ�������\n");
                return 1;
        }

        max_count = ob->query_amount();
        if( !max_count )
        {
                // not combined object
                if( amount > 1 )
                {
                        write(ob->name() + "���ֶ������ܲ����ġ�\n");
                        return 1;
                }
                max_count = 1;
        } else
        {
                // is combined object
                if( amount > max_count )
                {
                        write("������û����ô��" + ob->name() + "��\n");
                        return 1;
                }
        }


        if( ob->is_character() )
        {
                write(CYN + name() + "���ȵ������ⶫ��Ҳ�ܶģ�����\n" NOR);
                return 1;
        }

        if( query("unique", ob)
        ||  query("no_pawn", ob)
        ||  query("replica_ob", ob) )
        {
                write(CYN + name() + "ҡҡͷ�����������ֶ�����"
                      "��ʶ�������ҽӡ���\n" NOR);
                return 1;
        }

        if( query("no_drop", ob) ||
            (ns = query("no_sell", ob)) )
        {
                write(CYN + name() + "ҡҡͷ�����������ֶ�����"
                      "��ʶ�������ҽӡ���\n" NOR);
                return 1;
        }

        if( query("food_supply", ob)
        ||  ob->is_liquid() )
        {
                write(CYN + name() + "��м�������ٺ٣�ʣ��ʣ������"
                      "���Լ��ðɡ���\n" NOR);
                return 1;
        }

        if( query("shaolin", ob) )
        {
                write(CYN + name() + "��������С�ĵ��Ӻ�С����"
                      "���Ҷ������������\n" NOR);
                return 1;
        }

        if( query("mingjiao", ob) )
        {
                write(CYN + name() + "æҡͷ������С��ֻ��һ���Դ�����"
                      "���Ҷ�ħ�̵Ķ�������\n" NOR);
                return 1;
        }

        if( sscanf(base_name(ob), "/data/%*s") )
        {
                write(CYN + name() + "˵����������㣬���󶨹��Ķ�����������ƭ�˰�����\n" NOR);
                return 1;
        }
        
        //"/inherit/template/armor/armor"
        if( sscanf(base_name(ob), "/inherit/template/%*s") )
        {
                write(CYN + name() + "˵���������ֶ������ܶġ���\n" NOR);
                return 1;
        }


        if( query("consistence", ob) )
                value = value * query("consistence", ob) / 100;

        if( max_count > 1 )
        {
                if( query("base_value", ob) * amount / amount != query("base_value", ob) )
                {
                        write(CYN + name() + CYN "��ʧɫ������ô��һ�����⣿��"
                              "�ɲ�������\n" NOR);
                        return 1;
                }
                value = query("base_value", ob) * amount;
        }
        else
                value = query("value", ob);

        if( value < 2 ) {
                write(CYN + name() + "����һ�ӣ�����" + query("name", ob) +
                      CYN "һ�Ĳ�ֵ��\n" NOR);
                                return 1;
        }
        
                if( query("bind_owner", ob) || query("bindable", ob) )
                {
                        write(CYN + name() + "˵����������㣬���󶨹��Ķ�����������ƭ�˰�����\n" NOR);
                        return 1;
                }
                
                if (a_amount) {
                        if (query("id", me)==a_id) {
                                write(CYN + name() + "��Ц�������Լ����Լ��棬��û���հɣ���\n" NOR);
                                return 1;
                        }
                        
                        if (base_name(ob)!=a_file) {
                                write(CYN + name() + "��Ц��˵������ô���ó����Ķ����ͶԷ��Ĳ�һ�°�����\n" NOR);
                                return 1;
                        }

                        if (amount!=a_amount) {
                                write(CYN + name() + "��Ц��˵������ô���ó�������Ŀ�ͶԷ��Ĳ�һ��������\n" NOR);
                                return 1;
                        }
                        
                }

                if (query("base_unit", ob)) {
                        units = query("base_unit", ob);
                }
                else if (query("unit", ob)) {
                        units = query("unit", ob);
                }
                else {
                        units = "��";
                }

        message_vision("$N�ó�" + chinese_number(amount) + units +
                                       query("name", ob) + "(" + query("id", ob) + ")" + "����$n��\n",
                                       this_player(), this_object());
        
        if (a_amount) {
                b_id = query("id", me);
                usrb = me;
                b_name = query("name", me);
                                set("yangyong/time_start", time());
                                remove_call_out("do_return");
                call_out("do_start", 3, 0);
                                log_file("static/yangyong", sprintf("  -%s(%s)���㡣\n",  b_name, b_id)); 
        } else {
                a_id = query("id", me);
                usra = me;
                a_name = query("name", me);
                a_amount = amount;
                a_file = base_name(ob);
                ob_name = query("name", ob);
                call_out("do_return", 120);
                //����һ�¹���
                CHANNEL_D->channel_broadcast(CHANL_NAME, NOR + a_name + NOR + "�ó�" + chinese_number(a_amount) + units + ob_name + "(" + query("id", ob) + ")" + NOR + "�����µĶĵ��ϵȴ���ս��\n" + NOR);
                        log_file("static/yangyong", sprintf("(%s)%s(%s)������Ѻ��%d��%s(%s)��\n",  ctime(time()), a_name, a_id, a_amount, ob_name, a_file)); 
        }
        
                if( max_count == amount ) {
                        destruct(ob);
                }
                else
                {
                        ob->add_amount(-amount);
                }
                
                write(CYN + name() + "����˵�������ز��⣬�������⣬��׼���ߣ�����ร�ɡ���\n" NOR);
                me->start_busy(999);                
        return 1;
}




int ask_nt()
{
                int amount;
        object me = this_player();
        
                if(!interactive(me) || !playerp(me) || me->is_busy()) return notify_fail("����æ���ء�\n");
        
        if( query("online_time", me) < 3600){
                tell_object(me,CYN + query("name") + CYN + "����ؿ�����һ��˵�����������İ�..��...��\n"+ NOR); 
                return 1;
        }      

        amount = MEMBER_D->db_query_member(me, "money");
        
        if( amount < 102){
                tell_object(me,CYN + query("name") + CYN + "���Ť����˵�����˻���û��102 $NT���һ�ѽ��\n"+ NOR); 
                return 1;
        }
        
        if (!query_temp("yangyong/nt", me)) {
                tell_object(me,CYN + query("name") + CYN + "���е�˵��ȷ��Ҫ�һ����ٴ�����<ask yang yong about NT>��\n"+ NOR); 
                set_temp("yangyong/nt", 1, me);
                return 1;
        }

                me->start_busy(2);

                amount -= 102;
        if (!MEMBER_D->db_set_member(me, "money", (amount)))
        {
                write("�һ�ʧ�ܣ����뱾վADMIN��ϵ��\n");
                return 1;
        }
        write(HIG + "�������ĸ����㣺��Ա�˻����: (" + amount + ") $NT��\n" + NOR);

        new(__DIR__"obj/ntb")->move(me);
        message_vision(YEL + "$N" + NOR + YEL+ "��" + query("name") + NOR + YEL+ "����ӹ�һ�Ű�Ԫ�䶯��;�ҡ�\n" + NOR, me);        
        log_file("static/yangyong3",sprintf("%s %s 100 $NT -> ��Ԫ�䶯��;��, �˻��� %d $NT\n",TIME_D->replace_ctime(time()), query("id", me), amount));
       
        return 1;
}      

void create()
{
        set_name(NOR "����" NOR, ({ "yang yong", "yang" }));
         set("nickname", HIK "�����ϰ�" NOR);
        set("long", @LONG
���ϱ߾�����˽�����ļ��̣��˳��������ڹ��������Ҹ������˸�ġ�
LONG);
        set("gender", "����" );
        set("age", 38);
        set("attitude", "friendly");
        set("max_jing", 50000);
        set("max_qi", 50000);
        set("max_jingli", 50000);
        set("jingli", 50000);
        set("max_neili", 50000);
        set("neili", 50000);
        set("jiali", 350);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        set("per", 13);
        set("combat_exp", 1333000);

        set("inquiry", ([
                "nt"   : (: ask_nt :),
                "NT"   : (: ask_nt :),
                "�Ĳ�˵��"     : "֧��������ҶԶģ�ʹ��<bet ���� id��>���Ϳ��԰���ƷѺ������\n"+NOR,
                "�һ�˵��" : "���member�˻�����102 $NT������<ask yang yong about NT>�һ���һ�Ű�Ԫ�䶯��;�ҡ�\n"+NOR,
                "����˵��"     : "֧��������ҶԶģ�ʹ��<bet ���� me>���Ϳ���Ѻ�ϼ�����������ʦ���ڴ���Ч��\n"+NOR,
        ]));

        setup();
        carry_object("/clone/misc/cloth")->wear();

}



void init()
{
        if (! interactive(this_player())) return;
        add_action("do_bet", "bet");
        add_action("do_accept", "accept");
        add_action("do_no", "no");
}



