inherit NPC;
#include <ansi.h>

string clear_degree(string arg);
int add_degree(object ob);

void create()
{
        set_name(HIY"��һ��"NOR, ({"zhao yiren", "zhao", "yiren"}));
        set("nickname", HIR"��������"NOR);
        set("gender", "����");
        set("age", 41);
        set("long", 
         "�����ǵ���������������������һ�ʣ��ڳ��м���Ȩ�ơ�\n"
        );

        set("attitude", "friendly");
        set("per", 20);
        set("str", 40);
        set("int", 20);
        set("con", 30);
        set("dex", 25);

        set("chat_chance", 5);

        set("chat_msg", ({
        "��һ��̾�˿������������ôûʲô���������ˣ�����������취�ˡ�\n",
        }));

        set("inquiry", ([
        "����" : "Ҫ��ȡ�������ð��������Ϸ�������岻�ʣ����������", 
        ]));

        setup();
        carry_object("clone/misc/cloth")->wear();
}

int add_degree(object ob)
{
        string degree,old_degree;

        degree=HIR "�ᶽ" NOR;
        if( query("degree", ob))old_degree=query("degree", ob);
        else old_degree="";

        message("channel:rumor",MAG"�����ξ��ǡ�"HIY"����������ʵ�گԻ��"
        +"�߷�"+old_degree+""+HIW+query("name", ob )
        +HIY" Ϊ���� "NOR+degree+HIY"���մˣ�\n"NOR,users());
        delete_temp("degree_jungong", ob);

        if( query("degree", ob) )
        {
         if( query("degree_ask", ob) )
         degree=HIM"��"NOR+clear_degree(query("degree", ob) )
              +HIM " �� " NOR+degree+HIM " �� "NOR;
          else
         degree=HIM"��"NOR+clear_degree(query("degree", ob) )
              +degree+HIM " �� " NOR;
        } else
         degree=HIM " �� " NOR+degree
              +HIM " �� " NOR;               

        set("degree_jungong", 8, ob);
        set("degree", degree, ob);
        set("guo_shoucheng/reward", 8100, ob);
        return 1;
}

string clear_degree(string arg)
{
        if ((strsrch(arg, BLU "ʿ��" NOR) >= 0) ||
            (strsrch(arg, BLU "�λ�" NOR) >= 0) ||
            (strsrch(arg, HIC "�ν�" NOR) >= 0) ||
            (strsrch(arg, HIC "�Խ�" NOR) >= 0) ||
            (strsrch(arg, HIY "����" NOR) >= 0) ||
            (strsrch(arg, HIY "����" NOR) >= 0) ||
            (strsrch(arg, HIR "����" NOR) >= 0) ||
            (strsrch(arg, HIR "�ᶽ" NOR) >= 0) ||
            (strsrch(arg, HIM " �� " NOR) >= 0))
        {
                arg = replace_string(arg, BLU "ʿ��" NOR,"");
                arg = replace_string(arg, BLU "�λ�" NOR,""); 
                arg = replace_string(arg, HIC "�ν�" NOR,"");
                arg = replace_string(arg, HIC "�Խ�" NOR,"");   
                arg = replace_string(arg, HIY "����" NOR,"");
                arg = replace_string(arg, HIY "����" NOR,"");   
                arg = replace_string(arg, HIR "����" NOR,"");
                arg = replace_string(arg, HIR "�ᶽ" NOR,"");   
                arg = replace_string(arg, HIM " �� " NOR,"");
        }
        return arg;
}

int accept_object(object who, object ob)
{
        if( query("degree_jungong", who) >= 8 || query("guo_shoucheng/reward", who) >= 8100 )
        {
         message_vision("$Nһ���߿�������ͬ��Ϊ�٣����ʹ���ֲ��ʲ���"
                        +"֮�٣���ѽ����"+query("name", who )
                        +"���Һ��ȥ����\n"+"$n��һȺ�ҽ����ƴ���غ�"
                        +"�������鸮����\n"NOR,this_object(),who);
         who->move("/maze/battle3/ydmen");
         return 0;
        }

        if( query("money_id", ob) && ob->value() >= 10000000 )
        {
          message_vision(HIW"$Nһ������ʱЦ�մ󿪣����Ժ�Ϸ�Ϊ�����"
          +"���ߡ�\n", this_object());
          this_object()->move("/maze/battle3/cddian");
          call_out("add_degree",10,who);
          return 1;
        } else
        {
          message_vision(HIY"$N��ŭ�����ҹ���ȥ��$n��һȺ�ҽ����ƴ����"
           +"��������鸮����\n"NOR, this_object(),who);
          who->move("/maze/battle3/ydmen");
          return 0;
        }
}
