// daya.c 
//���Ž����ؼ�
//by dream @TXWX 2006.8.27 YC

inherit ITEM;
inherit F_UNIQUE;
#include <ansi.h>; 
void setup()
{}
void init()
{
        add_action("do_du", "du");
        add_action("do_du", "study");
}
void create()
{
        set_name(HIR"�����ŹŽ���"NOR, ({ "daya book1","book1", }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "paper");
                set("no_drop", "�������������뿪�㡣\n");
                set("no_get", "�������������뿪�Ƕ���\n");
                set("no_put", "�����������ܷ����Ƕ���\n");
                set("long",
        "����һ����Ƥ���Ƶ��ƾɹű������飺�����ŹŽ��� �ϲ᡹��\n"
        "�����Ѿ�����ܾ��ˡ�\n", );
        }
}

int do_du(string arg)
{
        object me = this_player();
        object where = environment(me);
        object ob;
        mapping skill;
        int pxlevel; 
	int neili_lost;

	if (!(arg=="daya book1" || arg == "book1"))
	return 0;
        if (where->query("pigging")){
                write("�㻹��ר�Ĺ���ɣ�\n");
                return 1;
        }
        if (me->is_busy()) {
                write("��������æ���ء�\n");
                return 1;
        }
        if( me->is_fighting() ) {
                write("���޷���ս����ר�������ж���֪��\n");
                return 1;
        }
        if (!id(arg)) {	
                write("��Ҫ��ʲô��\n");
                return 1;
        }
        if( !me->query_skill("literate", 1) ){
                write("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");
                return 1;
        }
        message("vision", me->name() + "�����ж����ŹŽ��ؼ�.\n", environment(me), me);
        if( (int)me->query("jing") < 500 ) {
                write("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");
                return 1;
        }
	neili_lost = 5;
        if( (int)me->query("neili") < neili_lost) {
		write("�������������޷�������ô������书��\n");
                return 1;
        }
        pxlevel = me->query_skill("daya-jian", 1);
        if( (int)me->query("combat_exp") < (int)pxlevel*pxlevel*pxlevel*500) {
                write("���ʵս��Ϊ���㣬����ô��Ҳû�á�\n");
                return 1;
        }
        if( me->query_skill("daya-jian", 1) > 99){
                write("���ж���һ��������Ƿ���������˵�Ķ���\n"
                       "���Զ�̫ǳ�ˣ�û��ѧ���κζ�����\n"
                        "Ҫ����һ��ֻ�еȴ���Ե�õ��²���.\n");
                return 1;
        }
        if( me->query("int", 1) < 30){
                write(HIR"������Բ���,�㻹����ѧϰ��ô������书,\n"
                          "����ȥ��Լ���ѩ��������!\n"NOR);
                return 1;
        }
        if( me->query("age", 1) < 36){
                write(HIR"��̫������,����ѧϰ��ô�������书..\n"NOR);
                return 1;
        }
        if((int)me->query("kill/japan")<1)
        {
                write(HIR"����ؼ���ô����?͵����?\n"NOR);
                return 1;
        }
        me->receive_damage("jing", 500);
	me->set("neili",(int)me->query("neili")-neili_lost);
        me->improve_skill("daya-jian", (int)me->query_skill("literate", 1)/3+1)
;
        write("���ж��п���Ž����������ĵá�\n");
        return 1;
        
}

