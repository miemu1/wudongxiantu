
#include <ansi.h>
int qilin_xiao();
inherit NPC;
void create()
{
	set_name(BMAG "������ż"NOR, ({"ren"}) );
	set("long",  "���Ǻ���ħ����������ż���ṩ����ǲ��Լ��ܼ��˺���");
	set("gender", "����");
	set("age", 999);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("qi", 1000000000);
	set("max_qi", 1000000000);
	set("max_jing", 1000000);
	set("neili", 1000000);
	set("max_neili", 1000000);
	set("combat_exp",100000000);
    set("chat_chance_combat", 90);
    set("chat_msg_combat", ({
                (: qilin_xiao :)
 }));
	setup();      
 carry_object("/clone/cloth/cloth")->wear();
 }               		
                		
int qilin_xiao()
{
        call_out("qilinyan", 1);
        return 1;
}

int qilinyan()
{
        int i;
        int dam;
        object *inv;
        inv = all_inventory(environment(this_object()));
        if (random(20) <= 5)
        {
        set("qi", 1000000);
        set("max_jing", 1000000);            
        message_vision( HIM"\n������ż�ָ���Ѫ����\n",this_object());   
        }
        
        return 1;
}

 void die()
{
       ::die();
}
 