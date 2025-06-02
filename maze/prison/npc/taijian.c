#include <ansi.h> 
inherit NPC;

object *players = ({});

void set_players(object *ob) {
        players = ob;
}

void add_player(object ob) {
        if(member_array(ob,players)==-1) {
                players += ({ob});
                message_vision(BLU"$N��$n˵����лл��\n"NOR,this_object(),ob);
        } else
                message_vision(BLU"$N��$n˵�������Ѿ���Ӧ��æ���㲻�ᷴ�ڰɣ�\n"NOR,this_object(),ob);
}

object* query_players() {
        players -= ({0});
        return players;
}

void play_sound_0(object speaker,int index);

void create()
{
        set_name("̫��", ({ "tai jian","tai", "jian" }) );
        set("gender", "����" );
        set("age", 40);
        set("str", 50);
        set("con", 30);
        set("dex", 22); 
        set("int", 50);
 
        set("long","���ǻʹ��ڵĻʵ����Էǳ��ó�һ��̫�ࡣ");
        set("max_qi", 8000000);
        set("eff_qi", 480000);        
        set("max_jing", 8500000);
        set("eff_jing",850000);
        set("neili", 8000000);
        set("max_neili", 4500000);
        set("max_jingli", 500000);
        set("combat_exp", 300000000);

        set_skill("force", 2000);
        set_skill("parry", 2000);
        set_skill("dodge", 2000);
        set_skill("sword", 2000);
        set_skill("unarmed", 2000);
        set_skill("pixie-jian", 2000);        
        set_skill("literate", 2000);
        set_skill("martial-cognize", 2000);
        set_skill("kuihua-mogong", 2000);

        map_skill("force", "kuihua-mogong");
        map_skill("dodge", "kuihua-mogong");
        map_skill("unarmed", "kuihua-mogong");
        map_skill("sword", "kuihua-mogong");
        map_skill("parry", "kuihua-mogong");

        prepare_skill("unarmed", "kuihua-mogong");

        set_temp("apply/attack", 3000);
        set_temp("apply/defense", 3000);
        set_temp("apply/damage", 1500);
        set_temp("apply/unarmed_damage", 1500);
        setup();
        
        carry_object("/d/fuzhou/obj/xiuhua")->wield();
        carry_object("/d/wanjiegu/npc/obj/qi-dress")->wear();
}  

void init()
{       
        object ob; 
        ::init();
        
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_answer", "answer");
        add_action("do_accept", "accept");
        add_action("do_help", "help");
} 

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        if( query_temp("�����׽���") || query_temp("��ʼ˵������") || query_temp("����") )
                return;
                
        message_vision(CYN "$N����������˵������λ" + RANK_D->query_respect(ob) +
                "��������Ϊ�ʹ����������𣿣�(answer yes/no)\n" NOR, this_object(), ob);
} 

int do_answer(string arg) {
        if(arg=="yes") {
                if(query_temp("in_speech"))
                        return 0;
                if(present("tape",environment()))
                        return 0;
                set_temp("��ʼ˵������",1);
                set_temp("in_speech", 1);
                play_sound_0(this_object(),0);
        } else if(arg=="no") {
                message_vision(BLU"$N˵����˭���������̫��ϻ���\n",this_player());
        } else
                return notify_fail("��Ҫ�ش�ʲô��\n");
        return 1;
}

void play_sound_0(object speaker,int index) {
        if(!environment())
                return;
        if(!speaker)
                return;        
        switch (index)  {
                case(0):
                        tell_room(environment(),CYN"̫��˵���������ܹ�̫���ܹ�����Ӣ�������ж�����һ����ʿ����ɱʥ��......\n"NOR);
                        break;
                case(1):
                        tell_room(environment(),CYN"̫��˵��������������ʿ�����������������ϣ��书��ǿ������ʥ��Ѱ���λ��ʿǰ��������\n"NOR);
                        break;
                case(2):
                        tell_room(environment(),CYN"̫��˵������Ը��Ϊ��͢�������棬��������Ӣ��(accept yes/no)\n"NOR);
                        speaker->set_temp("�����׽���",1);
                        break;
                default: 
                        speaker->delete_temp("in_speech");
                        return;

        }
        call_out("play_sound_0",1,speaker,++index);
}

int do_accept(string arg) {
        object ob,*team;
        object me = this_player();
        if(!query_temp("�����׽���"))
                return 0;
        if(query_temp("����"))
                return 0;
        if(arg=="yes") {                
                delete_temp("�����׽���");
                team = me->query_team();
                if(!team || sizeof(team)==0)
                        team = ({ me });
                set_players(team);
                set_temp("����", 1);
                ob = new("/maze/prison/npc/obj/key");
                ob->move(me, 1);
                tell_room(environment(),CYN"̫��˵�������ǽ������ε�Կ�ף����ڽ����㣬ϣ��" + RANK_D->query_respect(me) + 
                        "�����ʥ�Ϸ�������������\n" NOR);
                message_vision(HIY "$N" HIY "˵��" HIY "������$n" HIY "�첽�������η���ȥ��\n\n" NOR, this_object(), me);
                me->move("/maze/prison/tianlao");
                tell_object(me, CYN + name() + "˵������������������Ϳ����ˡ�\n"
                        HIC + name() + "˵��㼱��ææ���˻�ȥ��\n" NOR);                
        }        
        else if(arg=="no") {
                delete_temp("�����׽���");
                delete_temp("��ʼ˵������");
                message_vision(BLU"$N˵����û�ô��������ҿɲ��ɣ�\n",this_player());
        }
        else
                return 0;
        return 1;
}

int do_help(string arg) {
        if(arg!="tai" && arg!="tai jian")
                return 0;
        add_player(this_player());
        return 1;
}
