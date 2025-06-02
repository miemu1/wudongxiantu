// This program is a part of NT MudLIB 
 
#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
        set_name(HBGRN "����ħ��" NOR, ({ "xingtian sword", "sword" }));
        set_weight(500);
        /*if (clonep())
                set_default_object(__FILE__);
        else*/
        {
                set("unit", "��");
                set("long", HIY "�������������ʹ�õ�ħ��������Ѫ����졣\n"
                            HIY + name() + HIY "�ĵȼ����Ϲ���Ʒ  LV10\n" NOR);
                set("value", 3000); 
                set("no_sell", "����������������\n");
                set("rigidity",8000);   
                set("material", "tian jing");
                set("no_pawn", 1);
                set("no_store", 1); // �����øɽ�����upd
                set("no_save", 1); // quit������
        }     

        set("mod_mark", "A2033");
        set("mod_level", "M2030");
        set("mod_name", HBRED "������װ" NOR);
        init_sword(50000);
        set("quality_level", 3);
        
        setup();
}

void start_borrowing(int time) 
{
        remove_call_out("return_to_back"); 
        call_out("return_to_back", time); 
} 

void return_to_back() 
{ 
        object me; 

        me = environment(); 
        if( !objectp(me) ) 
                return;

        while( objectp(environment(me)) && !playerp(me) ) 
                me = environment(me); 
        
        if( playerp(me) ) 
        { 
                if( me->is_fighting() ) 
                { 
                        call_out("return_to_back", 1); 
                        return; 
                } 

                tell_object(me, HIR"\nһ����Ӱ������ǰһ��������" +
                            "��ʱ���ѵ����Ϸ�ȡ��" NOR + name() + HIR
                            "���ʹ�л�������Ǻ�����ڣ���\n\n"NOR);
        } else 
        { 
                message("vision", "��Ȼһ�������˹���������"+name()+"��̾�˿�����ҡҡͷ���ˡ�\n", me); 
        } 

        destruct(this_object());
}

