#include <ansi.h>
inherit ROOM; 

int do_knock(string arg);

void create()
{
        set("short","����԰");
        set("long",
"�㴦��һ��ֲ���軨�Ļ�԰���Ȼ�����ǿ�����ʱ�ڣ�������Щ��\n"
"�������Ĳ�������������е�������ˬ���ݴ�����ЩС�����������௵�\n"
"�е�������\n");
        set("exits",([ 
                "north"  : "/d/shenfeng/lvzhou",
        ]));
        setup();
} 

void init()
{
        add_action("do_knock","knock");
}

int do_knock(string arg)
{ 
        object *member;
        int i;
        object env;
        string *ips;

        member = this_player()->query_team();
       
        if (!arg || arg != "spiritgate")
        {
                return notify_fail("��Ҫ��ʲô��\n");
        }
        
        if( sizeof(member) != 4 )
                return notify_fail(HIG"������г�Ա��Ŀ��������Ϊ��֮�룬����֮�Ų��Ὺ����\n"NOR);

        if( ! this_player()->is_team_leader() )
                return notify_fail(HIG"���г�Ա��ֻ�жӳ����ܿ�������֮�š�\n"NOR);

        env = environment(this_player());
        ips = ({ query_ip_number(this_player()) });
        for(i=0;i<sizeof(member);i++)
        {
                if (environment(member[i]) != env)
                        return notify_fail("����г�Ա����û������ġ�\n");

                if (count_lt(member[i]->query("combat_exp"), 2000000)) 
                        return notify_fail("���г�Ա������Ϊ����̫�͵�,�����ǽ����˾����ġ�\n");
                        
                if (time() - member[i]->query("boss/dragon") < 3600)
                        return notify_fail(HIG "���г�Ա�������ϴ�����ʱ�䲻��һ��Сʱ������֮�Ų��Ὺ����\n" NOR);
        
                if (member_array(query_ip_number(member[i]), ips) == -1)
                        ips += ({ query_ip_number(member[i]) });
        }
        if (sizeof(ips) < 4)
                return notify_fail(HIG"���г�Ա��ֻ�� " + sizeof(ips) + " IP��ַ���ˣ�����֮�Ų��Ὺ����\n"NOR);

        for(i=0;i<sizeof(member);i++)
        {
                member[i]->move(__DIR__"spirit1"); 
                member[i]->set("fighter",0); 
                member[i]->set("mark/diary",0); 
                member[i]->set("boss/dragon", time()); 
                member[i]->set_temp("m_success/����",0);  
                member[i]->set_temp("m_success/��Ӱ",0);  
                member[i]->set_temp("m_success/����",0);  
                member[i]->set_temp("m_success/���",0);  
        }
        
        message_vision( HIG "$N�����������۶����£�һ�������������У�$N���͵���һ������ĵط���\n" NOR, this_player());
        message("channel:chat", HBMAG"��������硿����֮�ſ�����ĳС�ӽ����˾�����磬�ƽ������ķ�ӡ!\n"NOR, users());
        return 1;
}

