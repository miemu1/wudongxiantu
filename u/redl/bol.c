// This program is a part of NITAN MudLIB 
// redl 2012/11/1 
#include <ansi.h> 
inherit ITEM; 

void create() 
{ 
              set_name(HIC"ȵ��"NOR, ({"bridge oflove", "bridge"}) ); 
              set_weight(1); 
              if( clonep() ) 
                      set_default_object(__FILE__); 
              else { 
                      set("long", "����Redl������Gigi��ר��ͨ��������Ī��enter bridge��\n");  
                      set("unit", "��"); 
                      set("value", 10000);
                      set("no_get",1); 
              } 
              setup(); 
} 
       
void init() 
{ 
              add_action("do_enter","enter"); 
} 
       
int do_enter(string arg)  
{ 
                object me = this_player();
                string id = query("id", me);

                        if (! arg || (arg != "bridge" && arg != "bridge oflove" && arg != "ȵ��"))
                                return 0;
                
                        if(me->is_busy()) return 1;
                        
                if (id != "gigi" && id != "redl") {
                        tell_object(me, NOR "��о�ȵ������Ī�⣬��ԥ�о�������ǰ̤��벽��\n" NOR);
                                me->start_busy(1);
                        return 1;
                }
                
                message_vision(NOR"$N�����Ʋ�̤��" + HIC"ȵ��"NOR + "��\n" + "һ��" + HIW + BRED"��" + BGRN"��" + BYEL"��" + BBLU"�" + BRED"��" + BMAG"��" + BCYN"��" + NOR"ƽ������\n����$N������������֮���ȥ...\n", me);
                me->move("/u/redl/workroom");
                message_vision(NOR "$N�����Ʋ�����" + HIC"ȵ��" + NOR + "��\n", me);
                tell_object(me, NOR "(Ҫ���������룺y)\n" NOR);
                        input_to("get_bridge", me);
            return 1; 
} 
protected void get_bridge(string fun, object me)
{
            switch (fun)
        {
        case "y":
        case "Y":
                        tell_object(me, HIC"ȵ��"NOR + "����һ����â���������㻳�С�\n" NOR);
                        this_object()->move(me, 1);
                return;
        default:
                return;
        }
}

