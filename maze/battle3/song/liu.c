#include <ansi.h>
inherit NPC;

string *degree_desc = ({
       HIR "�ܶ�" NOR,
       MAG "��������" NOR,
       MAG "��������" NOR,
       HIB "�򱱽ڶ�ʹ" NOR,
       HIB "���ִ󽫾�" NOR,
       HIW "�����Ԫ˧" NOR,
});
string clear_degree(string arg);
string ask_chubing(object me);
int ask_degree();
int add_degree(object ob, int lv);

void create()
{
        set_name("������", ({"liu gonggong", "liu"}));
        set("gender", "����");
        set("age", random(20) + 20);

        set("long", "����һ�����ǻʹ��е�һ��̫�࣬����Ϊ�ʵ۴����౾��\n");
        set("combat_exp", 800000);
        set("attitude", "peaceful");
        set("max_qi", 3000);
        set("max_jing", 2000);
        set("max_neili", 2000);
        set("neili", 1000);
        set("no_get", 1);
        set("inquiry", ([
                 "�߷�" :   (: ask_degree :),
                 "����" :   (: ask_chubing :),
        ]));

        setup();
        carry_object("clone/cloth/cloth")->wear();
}

int ask_degree()
{
        int lv;
        object ob = this_player();

        if( query_temp("degree_jungong", ob) )
        {
                command("say �����԰����꣬"
                        + "�ۼ��Ѿ�����ʥ���ˣ����������Ĺ���ʥ��ּ��ɣ�\n");
                return 1;
        }

        if( query("guo_shoucheng/reward", ob)>
                (100*(1+query("degree_jungong", ob))*(1+query("degree_jungong", ob))) )
        lv=query("degree_jungong", ob)+1;

        if (lv > (sizeof(degree_desc) + 8))
        {
                command("say �����Ѿ��پӼ�Ʒ��λ��Ȩ�أ��ö࿼��Щ"
                        + "Ϊ�������������ǣ�\n");
                return 1;
        }

        if( lv <= query("degree_jungong", ob) || query("degree_jungong", ob)<8 )
        {
                command("say Ҫ��ø��ߵĲ߷⣬���������������󲻹�����\n");
                return 1;
        }

        command("say �������Ժ��ۼ������������ʥ�ϣ�Ϊ������⣡\n");

        //  remove_call_out("add_degree");
        call_out("add_degree", 10, ob, lv);
        set_temp("degree_jungong", 1, ob);
        return 1;
}

int add_degree(object ob, int lv)
{
        string degree, old_degree;
        degree = degree_desc[lv - 9];

        if (! ob) return;

        if( query("degree", ob))old_degree=query("degree", ob);
        else old_degree = "";

        message("channel:rumor", MAG"�����ξ��ǡ�"NOR + YEL
                + CHINESE_D->chinese_date((time() - 14 * 365 * 24 * 60 * 60))
                + "......\n"NOR,
                users());

        message("channel:rumor", MAG"�����ξ��ǡ�"HIY"����������ʵ�گԻ��"
                +"�߷�"+old_degree+""+HIW+query("name", ob )
                + HIY" Ϊ���� "NOR + degree + HIY"���մˣ�\n"NOR,
                users());
        delete_temp("degree_jungong", ob);

        if( query("degree", ob) )
        {
                if( query("degree_ask", ob) )
                        degree=HIM " �� " NOR+clear_degree(query("degree", ob) )
                               + HIM " �� " NOR + degree + HIM " �� "NOR;
                else
                        degree=HIM " �� " NOR+clear_degree(query("degree", ob) )
                               + degree + HIM " �� " NOR;
        } else
                degree = HIM " �� " NOR + degree
                       + HIM " �� " NOR;

        set("degree_jungong", lv, ob);
        set("degree", degree, ob);
        addn("weiwang", lv*200, ob);
        return 1;
}

string clear_degree(string arg)
{
        if ((strsrch(arg, HIR "�ᶽ" NOR) >= 0)
        ||  (strsrch(arg, HIR "�ܶ�" NOR) >= 0)
        ||  (strsrch(arg, MAG "��������" NOR) >= 0)
        ||  (strsrch(arg, MAG "��������" NOR) >= 0)
        ||  (strsrch(arg, HIB "�򱱽ڶ�ʹ" NOR) >= 0)
        ||  (strsrch(arg, HIB "���ִ󽫾�" NOR) >= 0)
        ||  (strsrch(arg, HIW "�����Ԫ˧" NOR) >= 0)
        ||  (strsrch(arg, HIM " �� " NOR) >= 0))
        {
                arg = replace_string(arg, HIR "�ܶ�" NOR, "");
                arg = replace_string(arg, MAG "��������" NOR, "");
                arg = replace_string(arg, MAG "��������" NOR, "");
                arg = replace_string(arg, HIB "�򱱽ڶ�ʹ" NOR, "");
                arg = replace_string(arg, HIB "���ִ󽫾�" NOR, "");
                arg = replace_string(arg, HIW "�����Ԫ˧" NOR, "");
                arg = replace_string(arg, HIR "�ᶽ" NOR, "");
                arg = replace_string(arg, HIM " �� " NOR, "");
                arg = replace_string(arg, HIM "��" NOR, "");
        }
        return arg;
}

string ask_chubing(string arg)
{
        object me;

        me = this_player();
        return WAR_D->ask_kingwar(me);
}
