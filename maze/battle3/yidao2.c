inherit ROOM;
#include <ansi.h>;

void create()
{
        set("short", "�������");
        set("long", @LONG
������ͨ�����ξ��ǵ����������������ս��ֹ���Եø����
��������ʱ����������ƥ�ɱ�����������һ�����̣���;��ʱ������
������֣���������ͣ���ĺá�
LONG );
        set("outdoors", "xiangyang");
        set("no_fly",1);

        set("exits", ([
                "east"  : __DIR__"yidao2", 
                "west"  : __DIR__"yidao2",
        ]));

        setup();
}

void init()
{
        object me=this_player();

        if (! me->is_busy())
        me->start_busy(random(1));


        if( query_temp("yidao/mark_steps", me)>11 )
        {
         me->move(__DIR__"yidao3");
         delete_temp("yidao", me);
         tell_object(me,YEL"һ·�糾����֮�������Ѿ�������ǰ��......\n"NOR);
         return;
        } 

        if( query_temp("yidao/mark_steps", me)<-11 )
        {
         me->move(__DIR__"yidao1");
         delete_temp("yidao", me);
         tell_object(me,YEL"һ·�糾����֮�������Ѿ�������ǰ��......\n"NOR); 
         return;
        }

        tell_object(me,YEL"�����ӱޣ�һ·�ɳ��������......\n"NOR);

}

int valid_leave(object me,string dir)
{
        object dadao,*env;
        int i,flag;
  
        env=all_inventory(environment(me));   
        flag=0;

        for(i=0;i<sizeof(env);i++)
        {
         if( objectp(env[i]) && query("id", env[i]) == "jiangyangdadao"
             && query("killer", env[i]) == query("id", me) )
         flag=1;
        }

        if( query_temp("warquest/purchase", me) && random(12)>10 )
        {
                dadao=new(__DIR__"npc/dadao");
                dadao->set_from_me(me);
                set_temp("warquest/party", "meng", dadao);
                dadao->move(environment(me));
                dadao->kill_ob(me);
                me->kill_ob(dadao);
        return notify_fail("��Ȼ��·�ߴ�����ɱ��һ·����\n");
        } else
        if(flag)
        return notify_fail("���������ס�����ȥ·��\n");

       if( dir == "east" )
       addn_temp("yidao/mark_steps", -random(2), me);
       if(  dir == "west" )
       addn_temp("yidao/mark_steps", random(2), me);
       return ::valid_leave(me,dir);
}
