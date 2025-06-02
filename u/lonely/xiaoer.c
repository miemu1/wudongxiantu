#include <ansi.h>
#include <command.h>

inherit NPC;

void greeting(object ob);
void remove_ct(object ob);

void create()
{
        set_name("��С��", ({ "xiao er", "xiao", "waiter" }) );
        set("gender", "����" );
        set("age", 22);
        set("long", "��λ��С����Ц�����æ��������ʱ������ڲ����ϵ�Ĩ��������\n");
        set("combat_exp", 100);
        set("attitude", "friendly");
        set("rank_info/respect", "С����");
        setup();
        if (clonep()) keep_heart_beat();
}

string accept_ask(object me, string topic)
{
        switch (random(5))
        {
        case 0:
                return "�ˣ���æ���أ������������¥������ֵ����İɣ�";

        case 1:
                return "���ɶ��û����æ����ô��";

        case 2:
                return "��ѽѽ����û����æ����ô��Ҫ������Ϣ��ȥ��������¥������ֵܰɣ�";

        case 3:
                return "������ݵ��ϰ��ﰢ��ɩ��ϢҲ��ͨ����Щү��ʲô����������Ҫ��������ȥ��";

        default:
               return "��������¥������ֵ���Ϣ�Ž���ͨ����ȥ�����İɡ�";
        }
}

void init()
{       
        object ob;

        ::init();

        if (interactive(ob = this_player()) && ! is_fighting())
        {
                remove_call_out("greeting");
                call_out("greeting", 5, ob);
                call_out("remove_ct", 3, ob);
        }
}

void remove_ct(object ob)
{
        remove_call_out("greeting");
}

void greeting(object ob)
{
        if ( ! ob || environment(ob) != environment() ) return;
        switch( random(2) )
        {
        case 0:
                say( CYN "��С��Ц�����˵������λ" + RANK_D->query_respect(ob)
                   + CYN + "�������ȱ��裬ЪЪ�Ȱɡ�\n" NOR);
                break;
        case 1:
                say( CYN "��С���ò����ϵ�ë��Ĩ��Ĩ�֣�˵������λ" + RANK_D->query_respect(ob)
                   + CYN + "����������\n" NOR);
                break;
        }
}


