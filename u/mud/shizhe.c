// This program is a part of NITAN MudLIB 
// mud 2015-3
#include <ansi.h>

inherit NPC;
int accept_object(object me, object obj)
{
        if (this_object()->is_busy())
        {
                tell_object(me, CYN + name() + "��ü����˵����û������æ���� \n" + NOR); 
                return 0;
        }
        if (!query("money_id", obj))
        {
                tell_object(me, CYN + name() + "��ü����˵������ֻ�ա�Ǯ���� \n" + NOR); 
                return 0;
        }
        
        if (obj->value() < 100000000)
        {
                tell_object(me, CYN + name() + "��ü����˵�����һ��ؼ���һ��һ��\n" + NOR); 
                return 0;
        }
        if (me->is_busy())
        {
                tell_object(me, CYN + name() + "��ü����˵�����Ȱ�����¶�æ����˵�ò��� \n" + NOR); 
                return 0;
        }
        else 
                me->start_busy(3);

        this_object()->command("say ��Ǯ���Ǻð��£�");
        this_object()->command("pat " + query("id", me));       
        addn_temp("invent/paid", obj->value(), me);
        destruct(obj); 
        
        return 1;
}

int ask_skill()
{
        object me, ob, obj;
        string book, *invent;
        mapping invent_skills;  
        int i;
        me = this_player();
        ob = this_object();
        
        invent_skills = query("invent", me);
        
        if( !invent_skills || !mapp(invent_skills) || !sizeof(invent_skills))
        {
                tell_object(me,CYN + query("name") + "������һ��˵���㻹û���Դ��书�ɣ�\n"+ NOR); 
                return 1;
        }      
        if( query_temp("invent/gived_"+query("id",me),ob)){
                tell_object(me,CYN + query("name") + "�ٺ�һЦ���´���������Ҫ�ɣ�\n"+ NOR); 
                return 1;
        }   
        if( ! query_temp("invent/paid",me)){
                tell_object(me,CYN + query("name") + "������Ц��˵����Ǯ��ʹ����ĥ���Ƚ�Ǯ�ɣ�һ��һ�򣬲����ۣ�\n"+ NOR); 
                return 1;
        }
    
        invent = keys(invent_skills);

        for(i=0;i<sizeof(invent);i++)
         {  
            book = invent_skills[invent[i]];
            obj = get_object("/data/book/" + book);
            obj->move(me);
            message_vision(MAG"$NĬ��ھ����������ǹ������˷������������ۼ������ᣡ\n"NOR,ob);
            message_vision(MAG"ͻȻ�䣬ϼ��һ����$N���ж���һ��"+obj->name()+NOR+MAG+"��\n"NOR,ob);         
            message_vision("$N�ó�"HIW+HBRED+obj->name()+NOR"�ؼ�����$n!\n",ob,me);
         }
        ob->command("sweat");
        set_temp("invent/paid",0,me);
        set_temp("invent/gived_"+query("id",me),1,ob);
        
        return 1;
}      
  
void create()
{
        set_name("�䶯��;ʹ��", ({ "nitan shizhe", "shizhe", "shi" }));
        set("nickname", HIW"�����ʹ�"NOR);

        set("long", @LONG
�����䶯��;����NPC��������ǲ����Ϊ����ṩ���ַ����ʹ�ߡ�
LONG);
        set("gender", "����" );
        set("age", 30);
        set("attitude", "friendly");
        set("max_jing", 50000);
        set("max_qi", 50000);
        set("max_jingli", 50000);
        set("jingli", 50000);
        set("max_neili", 50000);
        set("neili", 50000);
        set("jiali", 350);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        set("combat_exp", 1200000);
        set("inquiry", ([
                "�Դ��书" : (: ask_skill :),
                "�书�ؼ�" : (: ask_skill :),
        ]));

        setup();
        carry_object("/clone/misc/cloth")->wear();

}


