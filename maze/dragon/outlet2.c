#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "��ƺ");
        set("long",
"[1;32m����һƬ���̵Ĳ�ƺ������ȥ�����쳣�������º񣬲�ƺһ\n"
"ֱ���쵽С���ϣ�����ݸ�Ҳ�����ˮ֮�С������ϵ��˸��,��������\n"
"ᵴ������ƺ�����棬һ�øߴ����ͩ����֦��б�죬�������ٴִ�����\n"
"�����ǧ(qiuqian)��һ��������Ϣ�����ʱ�������������ס�ˣ������\n"
"�׷��ֻС���顣\n"
);
        set("exits", ([ 
        ]) );

        set("item_desc", ([
        "qiu qian": "��ǧϵ�ù�����ͣ���Ȼ��ª��ȴ������Ȥ����������ŵ���(swing)����\n",
        "tree": "�ߴ����ͩ���Ѳ�ƺ�ı����ڵ�����ʵʵ��\n",
        ]) );
        
        set("no_magic", 1);
	setup();
}

void init()
{
   add_action("do_swing", "swing");
     add_action("do_north", "beifang"); 
   add_action("do_north", "n");
}

int do_north(string arg)
{
   object me;

   me = this_player(); 

 if(me->query_temp("marks/marble"))
   {
message_vision(HIW"$N�ƹ���ͩ���������ݴԣ���Ȼһ���紵������$N���˸����ġ�\n"NOR,me ); 
message_vision(HIW"���д���һ���������¸ҵ��ˣ�лл��⿪��һ����ӡ����������ȥ�ɡ�\n"NOR,me );
message("channel:chat", HBMAG"��������硿"+me->query("name")+"�ɹ��⿪��һ����ӡ!\n"NOR,users());
      me->move(__DIR__"spirit5");
    me->set_temp("marks/marble", 0);
                me->set_temp("m_success/����",1);
   return 1;
   }
   else 
   tell_object(me, "����û�г�·��\n\n");
   return 1;
}

int do_swing(string arg )
{
        object me;
        me = this_player();

        if(!arg || arg != "��ǧ" && arg != "qiu qian" ) return 0;       
        switch (random (7)) {
                case 0:
message_vision(HIG"$N������ǧ�ϣ������ؿ�ʼ������ǧ��Խ��Խ�ߡ�\n"NOR, me);
                break;
                case 1:
message_vision(HIG"��ǧԽ��Խ�ߣ�$N���ɵý���ץס���١�\n"NOR, me);
tell_object(me, "��ֻ���÷�ӽŵ��ӹ������ƺ�Ҫ�˷��ȥ��\n");
                break;
                case 2:
message_vision(HIG"��ǧԽ��Խ�ߣ�$N���ɵý���ץס���١�\n"NOR, me);
message("vision", me->name()+"�ƺ�������ʲô�������Ҵҵش���ǧ������������\n", environment(me), me);
  tell_object(me, "���Ȼ����ǰ����ʲô����ҫ�۵Ĺ⣬��һ����ʧ���ƺ���������(beifang)��\n");
                me->set_temp("marks/marble", 1);
                break;
                case 3:
message_vision(HIR"��ǧԽ��Խ�ߣ�$Nһ���������ǧ�ϵ���������\n"NOR, me);
tell_object(me, "���飡�������ص�ˤ�������ϣ�ƨ�ɺ�ʹŶ�� \n");
                me->receive_damage("qi",25);   
                me->receive_damage("jing",20);   
                break;
                case 4:
message_vision(HIR"��ǧԽ��Խ�ߣ�$Nһ���������ǧ�ϵ���������\n"NOR, me);
tell_object(me, "���飡�������ص�ˤ�������ϣ�ƨ�ɺ�ʹŶ�� \n");
                me->receive_damage("qi",30);   
                me->receive_damage("jing",20);   
                break;
                case 5:
message_vision(HIR"��ǧԽ��Խ�ߣ�$Nһ���������ǧ�ϵ���������\n"NOR, me);
tell_object(me, "���飡�������ص�ˤ�������ϣ�ƨ�ɺ�ʹŶ�� \n");
                me->receive_damage("qi",50);   
                me->receive_damage("jing",20);   
                break; 
                case 6:
message_vision(HIR"��ǧԽ��Խ�ߣ�$N��һ��������ǧ�ϵ���������\n"NOR, me);
tell_object(me, "���飡�������ص�ˤ�������ϣ�ƨ�ɺ�ʹŶ�� \n");
                me->receive_damage("qi",40);   
                me->receive_damage("jing",10);   
                break;        }
        return 1;
}

