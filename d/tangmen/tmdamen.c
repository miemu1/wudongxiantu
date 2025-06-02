//tmdamen.c

inherit ROOM;
#include <ansi.h>;

int do_qu(string arg);
string look_bian();

void create()
{
        set("short","��������");
        set("long",
"һ����ΰ������һ�������ĺ�ǽ��һ���ֽ�Ĵ���(bian)���ô��\n"
"���ɣ�һ�ɾ�����Ȼ������������������ŵ���¥�ˡ���������������ģ�\n"
"����û�ж������������Ҳ���������˲��ڽ����߶���ԭ��ɡ��ſ�վ\n"
"�ż������ŵĵ��ӡ�\n"
);
        set("outdoors", "����");
        set("item_desc", ([
             "bian"  : (: look_bian :),
            ])); 
        set("exits", ([ 
            "enter"    : __DIR__"qianyuan",
            "southeast"    : __DIR__"gudao2",
        ]));
        set("objects", ([
            __DIR__"npc/tanggang" : 1,
            __DIR__"npc/dizi" : 2,
        ]));    
        set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_qu","qu");
}
        
string look_bian()
{
        object me;
        me = this_player();
        
        
        if ( me->query("tangmen/yanli") > 99 && !me->query_temp("dongdong") )
        {
               
              me->set_temp("dongdong",1);
              return HIC"�Һ��������һ������! �����ȡ����������\n"NOR;
        }
        
        return "�ĸ��ֽ���֣�"+HIY"�� �� �� �� \n"NOR;
                  
}

int do_qu(string arg)
{
        object me,ob;
        
        me = this_player();
        
        if ( !me->query_temp("dongdong") ) return 0;
        
        if ( me->query_temp("qudong") ) 
               return notify_fail(HIR"�Ĳ�Ҫ̫�ڰ���\n"NOR);
        
        if ( !arg || arg != "dongxi")
               return notify_fail("����ȡʲô����\n");
               
        if ( me->query_skill("dodge") < 120 )
               return notify_fail(HIR"�������̫���ˣ�\n"NOR);
               
        me->delete_temp("dongdong");
        ob = new("/kungfu/class/tangmen/obj/jie");
        tell_object(me,HIG"��õ���һ��������\n"NOR);
        me->set_temp("qudong", 1);
        ob->move(me);
        return 1;
}
/*
int valid_leave(object me, string dir)
{
        object guarder;

        if (! objectp(guarder = present("tang gan", this_object())))
                return 1;

        if (dir == "enter")
                return guarder->permit_pass(me, dir);

        return 1;
}
*/

int valid_leave(object me, string dir)
{

        if ( dir == "enter" && objectp(present("tang gang", environment(me))))
        {
                if ( !me->query("family") )
                {
                        return notify_fail( "��λ"+RANK_D->query_respect(me)+"Ҫѧ�յĻ������������᣿\n");
                }
               // if ( me->query("family/family_name") != "��������" )
              //  {
                  //      return notify_fail( "��λ"+RANK_D->query_respect(me)+"���������������ˣ���֪�����кθɣ�\n");  
              //  }    
                if ( me->query("tangmen/upshan") )
                {
                        if ( me->query("betrayer") )
                        {
                                tell_object(me,"�Ƹ�˵������������ɳܵļһ��\n");
                                return 0;
                        }
                        else 
                        {
                                tell_object(me,"�Ƹ�˵������ȥ�ɣ�\n");
                                me->move("/d/tangmen/qianyuan");
                                return 1;
                        }
                }                       
                else  return me->move("/d/tangmen/qianyuan");
        }// else 
       // if ( dir == "enter" )
     //  {
         //       if ( !me->query("family") || me->query("family/family_name") != "��������" ||
         //            !me->query("tangmen/upshan"))
         //               return notify_fail("��һ̧�㣬���ֵ����ж���æ�����˻ء�\n");                        
    //   }               
        return ::valid_leave(me, dir);
}

