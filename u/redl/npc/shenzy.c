// This program is a part of NITAN MudLIB 
// redl 2012/11/1 
inherit NPC;
#include <ansi.h>
int ask_makesan();
int ask_begdan();

void add_dan()
{
        set("guiyuan_dan", 1);
        call_out("add_dan", 3600);//ÿСʱ����1���ټŹ�Ԫ��
}

void create()
{
        set_name(NOR "��֥ع" NOR, ({ "shen zhiyu","shen" }) );
        set("title", HIG"��ҩʦ"NOR);
        set("nickname", HIM "������Ů" NOR);
        set("gender", "Ů��");
        set("age", 25);
        set("long", "����һ������ɢ����������Ϣ��Ů�ˣ���˵�����ſ�������ҩ֮����\n"
                                "ֻ���ж�СС��"+HIR+"Ѫ�컨��"+NOR+"��������������ָ�䲻ͣ��Ū��...\n");
        set("attitude", "friendly");
        set("str", 21);
        set("con", 19);
        set("int", 36);
        set("dex", 25);
        set("per", 29);
        set("kar", 30);
        set("level",50);
        set("medical_book", 100);
        
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
        

        set("chat_chance", 3);
        set("chat_msg", ({
                        //(: random_move :) , 
                CYN"��֥ع΢Ц��˵���䵱������ɢ��Ч�����棬�����÷���̫������\n"NOR ,
                CYN"��֥ع΢Ц��˵���䵱������ɢ��Ч�����棬�����÷���̫������\n"NOR ,
                CYN"��֥ع΢Ц��˵���䵱������ɢ��Ч�����棬�����÷���̫������\n"NOR ,
                CYN"��֥ع΢Ц��˵���䵱������ɢ��Ч�����棬�����÷���̫������\n"NOR ,
                CYN"��֥ع΢Ц��˵���䵱������ɢ��Ч�����棬�����÷���̫������\n"NOR ,
                CYN"��֥ع��Ц��˵����������ɢ֮������׿��������ˮ��֮����֮�ᴿȴ�Ǹ��ϲ�¥��\n"NOR ,
                CYN"��֥ع��Ц��˵����������ɢ֮������׿��������ˮ��֮����֮�ᴿȴ�Ǹ��ϲ�¥��\n"NOR ,
                CYN"��֥ع��ָ΢�����૵�����ô��Ƨ��ϴ��أ���˪Ũ�����ѩ���˻������ͽ�ĳ���\n"NOR ,
                CYN"��֥ع��ü��˼������Ϊ�������ӣ���ü������������ʱ�Ե��շ�һ��...\n"NOR ,
        }) );

        set("combat_exp", 300000000);

        set_skill("liandan-shu", 2500);
        
        set("inquiry", ([
                "����ɢ"   : (: ask_makesan :),
                "��Ԫ��"   : (: ask_begdan :),
                "������"     : "���ˮ׼�������Ѵ���������ɢ�����ң��Ұ�������������ɡ�\n"+NOR,
                "������"     : "���ǿ��Դ���������(liandan-shu)�ģ��ú�ѧϰ��..\n"+NOR,
                "����Ħ"     : "��Ҳ֪�����ֻ������ҿ�ϲ�����ˣ��´μ�������ժһ�����\n"+NOR,
                "����"     : "Hmm..˭��������̰�Եģ��ҿɴ�����ϲ������ʳ��Ŷ��\n"+NOR,
        ]));
        

        setup();
        carry_object("/d/city/npc/cloth/moon-dress")->wear();
        this_object()->apply_condition("die_guard", 999999999);
        set_temp("nopoison", 3, this_object()); 
                add_dan();
}



void fight_ob(object ob)
{
       ob->remove_enemy(this_object());
       this_object()->remove_enemy(ob);
       tell_object(ob,CYN + "��֥ع��һ˫�޹������������㣬���ᶼ��Ҫ�������ˡ�\n" + NOR + "��Ͻ���æ���ҵ�ͣ��������\n" + NOR); 
       return;
}

int accept_kill(object who)
{
       who->remove_enemy(this_object());
       this_object()->remove_enemy(who);
       return notify_fail(CYN + "��֥ع������գգ�ۣ�¶�����ص�΢Ц ... \n" + NOR + "�㷢���Լ���ôҲ�᲻�����֣�\n" + NOR); 
}

int accept_fight(object who)
{
       who->remove_enemy(this_object());
       this_object()->remove_enemy(who);
       return notify_fail(CYN + "��֥ع������գգ�ۣ�¶�����ص�΢Ц ... \n" + NOR + "�㷢���Լ���ôҲ�᲻�����֣�\n" + NOR); 
}

int accept_ansuan(object who)
{
       who->remove_enemy(this_object());
       this_object()->remove_enemy(who);
       return notify_fail(CYN + "��֥ع��Զ������գ�ۣ�¶�����ص�΢Ц ... \n" + NOR + "�㷢���Լ���ôҲ�᲻�����֣�\n" + NOR);
}

void receive_damage(string type, int n)
{
        full_self();
        return;
}

void receive_wound(string type, int n)
{
        return;
}

void unconcious()
{
        return;
}

void die(object killer)
{
        return;
}

void eat_mashu()
{
        this_object()->command("set careful");
        set("food", 0, this_object());
        this_object()->command("eat ma shu");
}

int accept_object(object me, object obj)
{
        int amount;
        object obz;
        
        if (me->is_busy())
        {
                tell_object(me,CYN + "��֥ع������ԳԵ�Ц������˵�����Ȱ�����¶�æ����˵�ò��� \n" + NOR); 
                return 0;
        }
        else 
                me->start_busy(3);

        if (query_temp("shenzy/givewan", me))
        {
                tell_object(me,CYN + "��֥ع������ԳԵ�Ц������˵������ô�ļ��ò��ã��ҵı�����«æ����... \n" + NOR); 
                 return 0;
        }
                
        switch (query("id", obj))
        {                       
         case "ma shu":
            if( stringp(query("food_race", obj)) || !query("food_remaining", obj) ) {
                tell_object(me,CYN "��֥عҡͷ����˵������..�����Ǹ��ҵ�ɶ�������\n" NOR); 
                return 0;
                }
            if( query("decay", obj) > 1 ) {
                tell_object(me,CYN "��֥عҡͷ����˵�����Ѿ������ˣ��������Ը����԰ɡ�\n" NOR); 
                return 0;
                }
                tell_object(me,CYN "��֥ع��������Ц����лл����ô�����ˡ�\n" NOR); 
                addn("shenzy/mashu", 1, me);
                obj = new(__DIR__"obj/yuqingb");
                obj->set_amount(1);
        obj->move(me);
        message_vision(YEL + "��֥عһ���������$N������ʱ����������һ��"+HIB+"��ɫСҩ��"+YEL+"��\n" + NOR, me);
        call_out("eat_mashu", 2 + random(6));
                return 1;
         case "yuqing san":
                if (!function_exists("query_amount",obj) || !query("only_do_effect", obj))
                {
                tell_object(me,CYN "��֥عҡͷ����˵������..�����Ǹ��ҵ�ɶ�������\n" NOR); 
                return 0;
                }

        if( query("family/master_name", me) != "������" && query("family/family_name", me) != "������")
        {
                tell_object(me,CYN "��֥عҡͷ����˵������ֻ������ɺ��䵱�����˵��ӣ��㻹�ǻ�ȥ�ɡ�\n" NOR); 
                return 0;
        }
        
                if( !query("is_alchemy", me) )
                {
                tell_object(me,CYN "��֥عҡͷ����˵��������ȥƽ������������ҩʦЭ���������Ұɡ�\n" NOR); 
                return 0;
                }
  
                obz = present("yaoshi zheng", me);
                if( !objectp(obz))
                {
                tell_object(me,CYN "��֥عҡͷ����˵������ҩʦЭ���ƽ���䷢�������ҩʦ֤�أ�\n" NOR); 
                return 0;
                }
                if (query("level", obz) < 3)//��ҩʦ֤С��3Ʒ����900��������+sk��װ����Ӱ��
                {
                tell_object(me,CYN "��֥عҡͷ����˵����������ҩˮƽҲ̫����Щ�ɣ���Ʒ�������µ�ӹ�ű������ҡ�\n" NOR); 
                return 0;
                }
                
                amount = obj->query_amount();
                amount /= 1000;
                
                if (amount < 1)
                {
                tell_object(me,CYN "��֥ع����ض���˵�����������ɢ̫�٣�����ֵ���ҳ���...\n" NOR); 
                return 0;
                }
         
                set_temp("shenzy/givewan", 1, me);
                amount *= 1000;
         
                if (obj->query_amount() > amount)
                {
                        obj->add_amount(- amount);
                        tell_object(me,CYN "��֥ع�����ͷ�������ˣ���ͷ�û�ȥ�����϶Ҹ��㡣\n" NOR); 
                        call_out("delay_givewan", 2, me, new(__DIR__"obj/yuqingb"), amount);
                        return 0;//�����ٲ�
                }
                else
                {
                        destruct(obj);
                        tell_object(me,CYN "��֥ع�����ͷ�����ðɣ����ĵȵȣ���ͶҸ��㡣\n" NOR); 
                        call_out("delay_givewan", 2, me, new(__DIR__"obj/yuqingb"), amount);
                        return 1;
                }
                
         default:
                return 0;
        }
}

void delay_givewan(object me, object obj, int amount)
{
                        obj->set_amount(amount / 1000);
                obj->move(me);
                message_vision(YEL + 
                "��֥عһ���������ŵ��Ͻ�С��«������$N������ɢ��\n" + 
                "����������$N������ʱ����������"+chinese_number(amount / 1000)+"��"+HIB+"��ɫСҩ��"+YEL+"��\n" + NOR, me);

                me->improve_skill("medical", amount * 25);
                me->improve_skill("liandan-shu", amount * 50);//������������ߵĻ��ᣬ��Ŀǰ����Ϸ��ʵ��ȱ�����Ⱦ�����������3Ʒҩʦ����Ϊ���ڴ����ˣ�100��Ҳ������
                
/*              ������1000w exp��õ��շ����ݶ�1������ɢ���5��exp��
                ��������ɢ�ļƻ����������24Сʱ1������ң���ô10idÿ��ɵ�50w exp�������ཨ���䵱��ɢ�������������
                ��Ϊ��ü�ɱ����������������ת����ÿ���ɳ�50w~200w expҲ����ʲô���Ͳ��÷ⶥ�����ȼ��ˣ� */
                
        if( query("family/family_name", me) == "������" && query("level", me) >= 10 )
        {
                GIFT_D->work_bonus(me, ([ "exp" : amount*5, "pot" : amount ]));
                }
                
                delete_temp("shenzy/givewan", me);
                return;
}



int recognize_apprentice(object me, string skill)
{
        //��ü��master��1000���������ٴ˸���900֧�֣��Ա�֤������3Ʒҩʦ
        if (query("family/family_name", me) != "������")
        {
        tell_object(me,CYN "��֥ع������˸�����������һЦ����ֻ����ڶ�ü����һЩ����֪ʶŶ..\n" NOR); 
        return -1;
        }

        if (skill != "liandan-shu")
        {
        tell_object(me,CYN "��֥ع������С���ս����ʵ�����.ȷ��..����ѧ��..����������(liandan-shu)...��\n" NOR); 
        return -1;
        }
        
        if ( me->query_skillo("liandan-shu", 1) >= 450 && query("shenzy/mashu", me)>random(100) && !query("can_make/�ټŹ�Ԫ��", me) ) {
        tell_object(me,HIG "��֥ع���ĸ����㣺�����ˣ�@*#^@^*#^@##$&**&\n" NOR); 
        tell_object(me,HIG "��֥ع���ĸ����㣺����ǰ㣬@!&#^%@&*$&#&&@&#@*$!^%@\n" NOR); 
                tell_object(me,YEL "�㾭����֥ع���ĵ㲦��ѧ�����ټŹ�Ԫ������������...\n" NOR); 
                set("can_make/�ټŹ�Ԫ��", "guiyuan", me);
        }
        
        
        if (me->query_skillo("liandan-shu", 1) >= 900)
        {
        tell_object(me,CYN "��֥ع������������ı���һ�����ɵúã������ڳ�ʦ�ˣ����ļ�Ц��\n" NOR); 
        return -1;
        }
        return 1;
}


int ask_makesan()
{
    object me = this_player();
    
        if (query("family/family_name", me) != "������")
        {
        tell_object(me,CYN "��֥ع������С���ս����ʵ�����.ȷ��..�����֪��ֻ�ж��ҵ��Ӹ�֪���ľ������ܣ�\n" NOR); 
        return -1;
        }

        if (me->query_skillo("liandan-shu", 1) < 300)
        {
        tell_object(me,CYN "��֥عһ��������������˵�������Ⱥú�ѧϰ��������...\n" NOR); 
        return -1;
        }

        if (query("medical_book") < 1)
    {
                command("say ���ǿ�ϧ���������ˣ������Ѿ����ȥ�ˡ�");
                return -1;
        }
        
        if (query_temp("shenzy/givebook", me))
    {
        tell_object(me,CYN "��֥ع��ͷ������һ���ƣ�̾���������ǳ������أ�\n" NOR); 
                return -1;
        }
        
        //���Ŷ�ü����ҩ����ɢ����ɢ�䵱������
        addn("medical_book", -1);
        message_vision(CYN "$n����һ����ɫС���ӵݸ�$N�������������㶮�ģ��úÿ���\n" NOR, me, this_object());
        new(__DIR__"obj/mbook")->move(me);
        set_temp("shenzy/givebook", 1, me);
        
        return 1;
}

int ask_begdan()
{
    object me = this_player();
    
        if (query("guiyuan_dan") < 1)
    {
                command("say ���ǿ�ϧ���������ˣ��ټŹ�Ԫ�����Ѿ��ͳ�ȥ�ˡ�");
                return -1;
        }
        
        if (query("family/family_name", me) != "������")
        {
        tell_object(me,CYN "��֥ع������С���ս����ʵ�����.ȷ��..�����֪��ֻ�ж��ҵ��Ӹ�֪���ľ������ܣ�\n" NOR); 
        return -1;
        }

        if (query("level", me) >= query("level"))
        {
        tell_object(me,CYN "��֥ع������ԳԵ�Ц������˵������Ƥ��ô��ô�񣬵ȼ����һ����˻������������䶫���֣�\n" NOR); 
        return -1;
        }

        addn("guiyuan_dan", -1);
        message_vision(CYN "$n�׸�$Nһ�ŵ���Сҩ�裬��üŪ�۵����Ӻã��ǵ���ǰ�ԣ�ǧ�������˰���\n" NOR, me, this_object());
        new("/clone/medicine/guiyuan")->move(me);
        return 1;
}








