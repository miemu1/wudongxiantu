inherit NPC;
#include <ansi.h>;


void create()
{       
        string *order = ({"��", "��", "��", "��", "��", "��", "֣", "��", "��",
                "��", "��", "��", "��", "��", "��", "κ", "��", "��", "��", "��"});
        string *orderr = ({"����", "����", "�Թ�", "СС", "����",
                "����", "ѻѻ", "����", "èè","����","����","�ɷ�"});
        set_name(order[random(20)]+orderr[random(8)], ({ "boy","nanhai" }) );
        set("title", "��֪�к�");
        set("gender", "����" );
        set("age",5+random(3));
        set("combat_exp", 100);
        set("attitude", "friendly");
        set("no_get", "1");
        set("d2name","");
        set("max_qi",100);
        set("max_jingli",100);
        /*
        set("chat_chance", 30);
        set("chat_msg", ({
                // (: random_move :)
        }) );
        */
        
        setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        add_action("do_dating","xunwen");
}       

int do_dating(string arg)
{       
        string str,where;
        object me = this_player();
        object ob = this_object();
        
        if ( !arg || arg != "wenzi")
             return notify_fail("����ѯ��ʲô���㵹��˵����\n");
        
        if ( query("dname") != me->query("id") )
             return notify_fail("�Ҳ���˵���㲻Ҫ�ʣ�����Ҳ���ʣ�\n");
             
        if ( (me->query_temp("askok")))
             return notify_fail("����������⣬��Ҫ����һ�£��������ǲ��Ǿ����е��Ȱ���\n");
        
        if ( !(me->query_temp("asked")))
             return notify_fail("���������֣�����·�ģ�����ҪǮ�ģ����ʳԵģ�û���������ӵġ�\n");
        
        switch( random(6))
        {
            case 0 : str = "�Ƽ�����";where = "/d/tangmen/tjpuzi";break;
            case 1 : str = "���ž�¥";where = "/d/tangmen/jiulou";break;
            case 2 : str = "�͵�";where = "/d/tangmen/kedian";break;
            case 3 : str = "ҩ��";where = "/d/tangmen/hcfdian";break;
            case 4 : str = "������";where = "/d/tangmen/tmbingqi";break;
            default : str = "����Ǯׯ";where = "/d/tangmen/tsqianz";break;
        }
        
        tell_object(me,HIC"��ȥ"+str+"���Ұ���\n"NOR);    
        
        me->set_temp("mingchen",str);
        me->set_temp("where",where);
            
        me->set_temp("askok",1);
        me->delete_temp("asked");
                        
        tell_object(me,HIC"�������䣬һ������û��Ӱ�ˣ�\n"NOR);
        destruct(ob);
        return 1;   
        
}                  

