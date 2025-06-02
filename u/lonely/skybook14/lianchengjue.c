#include <ansi.h>

#define DB_D          "/adm/daemons/dbd"
#define DIALOG_D      "/adm/daemons/dialogd"
#define SUICONG_D     "/adm/daemons/suicongd"
#define SKYBOOK_D     "/adm/daemons/skybookd"

inherit ITEM;

string *sBookMsg1 = ({
        "�㷭�������Ǿ�����˲�䣬һ����⽫�����֣��žɵ���ҳ�ϣ��Գ�һ����С�� ����",
        "�����Ǿ����˽�ӹ����������1963�꣬�����ڡ��������ܿ������������������Ľ�����֮�����Ϊ�����Ǿ�����",
        "��������������������ڽ��գ����¸��ˣ�ȫ�������һ�ɱ���֮�����������������ں�",
        "�����Ǿ���д��̬��д���ģ�д�����������������ǣ�ԶԶ������һ������С˵�ı��ַ��룬������ǡ����顱�������ܸ�������˵�ǽ�ӹ��Ʒ�е�����֮���� ",
        "���ڣ��㽫�����������ǵ��Ƶ���ݣ����롶���Ǿ�����������������һ�����صĹ��£�׼����������ʽ������������ ����        ",
        "=---------------------------------  ���Ǿ�  ---------------------------------=",
        HIY "�����¡�" NOR,
        "�����������һ����ͨũ�壬���׸�ĸ˫�������Ե�ɺϣ���һλ���ո�ǿ����������Ϊ���ӣ���λ���߽��ݳ�������һֱ����ʦ����",
        "ʦ����С����������ˣ��������գ���������������Ҳ��ʦ��������������һ�㣬������Ϊ���",
        "ʦ���и�Ů�������ݷ�������������ˣ��������С���꣬�����ʦ�ã���С�������÷�����޻���̸����δ��ʾ��ȴ�����϶��Է�Ϊ������¡�",
        "��ʦͽ���ˣ���������ũ�壬��ÿ����ũ��������ʦ��������ң����ʦ���д趺Ȥ�����������������Դһ�㣬�ò����Խ����ϵ�������һ����֪��",
        "��һ�����磬������һ����ʦ���������ö���ǰȥ�д����� ����",
});

string *sBookMsg2 = ({
        HIC "��ѧ���ˡ���ʫ��������" NOR,
        "���գ�ʦ���ݳ�������������ݷ�������ϰ��ʫ�������⽣���Դ��¾ͺ�ʦ��һ��ѧϰ����ʦ���ľ�ѧ��",
        "�ݳ�������Ϊʦ����������ʫ�����������û��������죬һ��Ҫ�����ϰ��" ,
        "��Ӧ�����ǣ�ͽ��һ���ڷ���ϰ��",
        "�ݳ�����ͷ�����ã��ã���Ϊʦ������������У�� ",
        HIC "������ʫ������������500��������(������ɺ�����skybook start ���Ǿ�)" NOR,
});

string *sBookMsg3 = ({
        HIG "�����ɣ�" NOR,
        "�㹧����������ʦ���ݳ�����ͷ����ʦ����ͽ������ʫ�����Ѿ����ô����ˣ���ʦ����У��",
        "�ݳ����������������Һͷ����д�һ�£�Ϊʦ���Կ������������Ĺ�����Ρ�" ,
        "��Ӧ�����ǣ�",
        HIC "���ܵ��µ��������� skybook cha ���Ǿ� �鿴����������" NOR,
});

string *sBookMsg4 = ({
        HIG "�����ɣ�" NOR,
        HIY "����һ�¡�����" NOR,
        "�ݳ���ͻȻ������������ͽ����� ����",        
        "�ݳ�������ͽ���书���г��������ǻ�δ�����շ����磬�Ժ󻹵��ڼ���ϰ���������ˡ�",
        "��˵�����ǣ�ʦ����",
        "�ݷ���ʦ�������۸��ң������ˣ�",
        "��Ǻ�Ц����ʦ�ñ��������Ժ�ʦ������������ˡ�",
        "�ݳ�������������ת���ˣ���ɽҰ֮�غ������أ�ͽ���п�ȥ��Щ�׺�Ƥ�������÷�������Ƥ��������",
        "��˵�����ǣ�ͽ�����ȥ��",
        HIC "���ܵ��µ��������� skybook cha ���Ǿ� �鿴����������" NOR,
});

string *sBookMsg5 = ({
        "�ݷ��ӹ������еİ׺�Ƥ��ϲ��ʦ�磬��׺�Ƥ�����ѵã�����Ƥ���ɻ�ѩ������֮��  ����",
        "�ݳ����Ǻ�Ц�����ݷ���ȥ׼���������ո���Ƥ���������µ�ȥ��ʦ��ϴ��  ����",   
        "ʦͽ������˵��Ц��һ������۶��� ����",
        "��������ʻ����ǰ�������ݳ�������������λ�����Ƿ��ݳ�����ʦ�壿",
        "�ݳ����������ߺ��ˣ�",
        "���˵���ԭ��������ʦ�壬�������ߣ�������ɽͽ�ܡ�",
        "�ݳ��������ҵ���˭��ԭ���Ǵ�ʦ�ֵĵ��ӣ�˵��ô���겻�������Һ��£�",
        "���ߵ���ʦ�������ٳ����ھ��������磬��������ʦ�帰�磡",
        "�ݳ��������Һʹ�ʦ�ֶ�ʮ�겻�����������������������ˣ��úã����ȥ�ɣ���������һ������",
        "����Ӧ�������ǣ��� ��޿����ȥ��",
        "�ݳ�����������ͽ�����ú���ʰһ��ϸ������������Ҫ�����ˣ������ʦ�����٣�",
        "����ݷ�ͬʱ˵�����ǣ�",
        HIC "���ܵ��µ��������� skybook cha ���Ǿ� �鿴����������" NOR,
});

string *sBookMsg6 = ({
        "��ʦͽ���˾�������·�̣����������˾��ݣ����������ҵ���  ����",
        "ֻ��������ͥ��������ǽ���ߣ�һ���󸻴��֮��  ����", 
        "����ǰ�ŵƽ�ʣ���ͥ���У�����֮�˴��󲻶ϣ��ò����֡�",
        "��ǰһλԼ����ʮ��������͵��ˣ����Ż���������������Ц����ӭ����ؾ�������ɽ�ˡ�",
        "����ݷ���С�����³���δ����������棬Ҳ�������˽�����ɵɵ��վ��һ�ԣ�ʦ���ݳ���������ɽ��˵�Ż�����",
        "ͻȻ�䣬һ��������������ɽ���˵�ǲ�������������֪�����˽���ͨ������ɽ�������˽������ӣ������˼���Ѱ������",
        "����ɽ���������ͨ�������Ϸ��ٳ������Ҷ�Թ�������ۣ��ٲ������뿪���ݹ������²����顣",
        "��ͨ��������ɽ����ڹ����˵�������ȫ�ң����ձض�����ƴ�������һ��",
        
        HIC "���ܵ��µ��������� skybook cha ���Ǿ� �鿴����������" NOR,
});

string *sBookMsg7 = ({
        "������ܴ����ͨ������ɽ���ֵ�����С�ֵܺ����֣���һ�Ե�����ɽ��������¶���á�",
        "����ɽ����ͽ�������������ӣ���ò������ֻ����ʱ��ʱ�ض��������Ե��ݷ�͵����",
        "����ɽ�к���������������ݷ���������ɽ�İ˸�������һ����ϯ�����˶��ݷ���ɫ�������ߣ����㼥����ӡ���",
        "��ɢ����ȥ��ҹĻ���� ����",
        "���ڿͷ��о�����ͻȻ����һ����У���Ѱ���ɱ���ȥ��ֻ��һ����Ӱ�ܽ�����ƫ����",
        "������ŷ�����뷿�䣬ֻ������һƬ��ڣ������к�Ӱ������ԥ�䣬�����͵�һ����",
        HIR "\n����ǰһ�ڣ�����ʲôҲ��֪���� ����\n" NOR,
        HIC "���ܵ��µ��������� skybook cha ���Ǿ� �鿴����������" NOR,
});

string *sBookMsg8 = ({
        "��������ת��ֻ������վ�����ˣ�������ɽ�İ˸����ӣ��мҶ����ݷ�Ҳ��һ���������ῴ���� ����",
        "����һ�����ӵ����벻���Ҽ�ʦ�������������磬��ȴ�����������������ʦ����С��Һ���Ҳ����",
        "����һ�����ӵ����ҿ�����ʦͽ������ʲô���ɸ��˵�Ŀ�ģ�ʦ�����ݳ������˺������ڴ����ݳ���������ò�����Ӱ�ˡ�",
        "�������������磬ȴ�����Լ��ѱ��廨��󣬻��������������������ô���£�ʦ���أ��Һ�����˭��ʦ�ã��⣬������ô���£�",
        "�ݷ��������ǣ�����˵������Һ죬����˵���ۿ�����������������ǻ�˵ʦ����������ǰ�������ˡ�",
        "˵�꣬�ݷ�৵��������� ����",
        "һ�����ӵ������װ���ˣ�������Ϳ��㲻�Ծ����벻�����������ˣ��ɴ��͹ٰɣ�",
        "���ԣ��͹٣��͹١��ܶ��˸��͡�",
        "���������ʦ�ã��㲻������ô�����Ǳ�ԩ���ģ��㲻������ô��",
        "�ݷ�������ʦ�磬���������š�˵��ֻ�ǵ�ͷ���ᣬ����������",
        "���ĵ���ʦ�ö���Ҳ��������Ⱥ����˵���Լ�Ī��ԩ����֪�δ���������С��÷�����ʦ�ã����������£����Ҳ�����������ʦ���Ǹ������ɣ�",
        "�������������ţ�������֣�",
        "����������˵�������Ǻ��͵�һ����������˹�ȥ��",
        HIR "\n����ǰһ�ڣ�����ʲôҲ��֪���� ����\n" NOR,
        HIC "���ܵ��µ��������� skybook cha ���Ǿ� �鿴����������" NOR,
});


string *sBookMsg9 = ({
        "��֪���˶�ã���������ת����Ȼ���ؽ��˼������Ĵ��İ��ޱȣ������󣬳�ζ���� ����",
        "�����������ȴ�����޷�����������˵һ������˺���ѷε�ʹ ����",
        "�㲻�������������Լ�����һ���ִ��������͸�����ù���ס��һ����ʹ������ ����",
        "��������ݺݵ�˵�����������������ɣ���������������ģ����Ȼ��������ң��Ⱳ�Ӿͱ����ȥ�ˡ�",
        HIY "���ڶ��¡�����" NOR,

        HIR "\n����ǰһ�ڣ�����ʲôҲ��֪���� ����\n" NOR,
        HIC "���ܵ��µ��������� skybook cha ���Ǿ� �鿴����������" NOR,
});


void create()
{
        set_name("����", ({ "skybook lianchengjue" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("value", 0);
                set_weight(0);
        }
        setup();
}

void start_story(int book)
{
        if( book == 1 ) SKYBOOK_D->broadcast_story(this_player(), sBookMsg1, 0, 2);
        else if( book == 2 ) SKYBOOK_D->broadcast_story(this_player(), sBookMsg2, 0, 2);
        else if( book == 3 ) SKYBOOK_D->broadcast_story(this_player(), sBookMsg3, 0, 2);
        else if( book == 4 ) SKYBOOK_D->broadcast_story(this_player(), sBookMsg4, 0, 2);
        else if( book == 5 ) SKYBOOK_D->broadcast_story(this_player(), sBookMsg5, 0, 2);
        else if( book == 6 ) SKYBOOK_D->broadcast_story(this_player(), sBookMsg6, 0, 2);
        else if( book == 7 ) SKYBOOK_D->broadcast_story(this_player(), sBookMsg7, 0, 2);
        else SKYBOOK_D->broadcast_story(this_player(), sBookMsg8, 0, 2);
}

void start_story1()
{
        "/adm/daemons/skybookd.c"->broadcast_story(this_player(), sBookMsg2, 0, 2);
}

void start_story2()
{
        "/adm/daemons/skybookd.c"->broadcast_story(this_player(), sBookMsg3, 0, 2);
}

// �ƶ������鸱��������flag ��ͬ���첻ͬ�ľ��鸱��
// flag���������ַ��䣬�����ʲô���ֵķ��䣬������ЩʲôNPC
// obx�����صĴ��������ͬʱ���������NPC����󷵻�һ��NPC��OB���,��Ϊ1�򷵻�ob1
object move_to_room(object me, int flag, int obx)
{
        object obroom;
        object ob1, ob2, ob3, ob4, ob5, ob6, ob7, ob8;
        
        switch(flag)
        {
        case 1: // �����㣬����é��ǰ
                obroom = new("/clone/skybook14/sky14room");
                obroom->set_name(HIG + "Сé��" + NOR, ({ "xiaomaowu" }));
              //obroom>set("long", "�����Ǳ����ǵĵذ��Ŵ�֡��ֵ�����������������֣������������ﲻ����\n������ƥ�������С�\n",");  
                obroom->set("long", "����������ũ���һ��ũ��СԺ��һ����ª��é��ǰ�ڷ���һ��ʯ����\n"); 
                obroom->set("create_time", time());
                ob1 = new("/clone/skybook14/lianchengjue/npc/qichangfa");
                ob2 = new("/clone/skybook14/lianchengjue/npc/qifang");
                ob1->move(obroom);
                ob2->move(obroom);
                me->move(obroom);
        break;
        case 2: // ��+��ͨ
                obroom = new("/clone/skybook14/sky14room");
                obroom->set_name(HIG + "����ǰ" + NOR, ({ "xiaomaowu" }));
              //obroom>set("long", "�����Ǳ����ǵĵذ��Ŵ�֡��ֵ�����������������֣������������ﲻ����\n������ƥ�������С�\n",");  
                obroom->set("long", "�����Ǿ����򸮣�������ɽ��ۡ���Ĵ���ǽ���ߣ��ò����ɡ�\n"); 
                obroom->set("create_time", time());
                ob1 = new("/clone/skybook14/lianchengjue/npc/lvtong");
                ob1->move(obroom);
                me->move(obroom);
        break;
        
        case 3: // �� ��NPC
                obroom = new("/clone/skybook14/sky14room");
                obroom->set_name(HIG + "����ǰ" + NOR, ({ "xiaomaowu" }));
              //obroom>set("long", "�����Ǳ����ǵĵذ��Ŵ�֡��ֵ�����������������֣������������ﲻ����\n������ƥ�������С�\n",");  
                obroom->set("long", "�����Ǿ����򸮣�������ɽ��ۡ���Ĵ���ǽ���ߣ��ò����ɡ�\n"); 
                obroom->set("create_time", time());
                me->move(obroom);
        break;

        case 4: // ���᷿ ��NPC
                obroom = new("/clone/skybook14/sky14room");
                obroom->set_name(HIG + "�᷿" + NOR, ({ "xiaomaowu" }));
              //obroom>set("long", "�����Ǳ����ǵĵذ��Ŵ�֡��ֵ�����������������֣������������ﲻ����\n������ƥ�������С�\n",");  
                obroom->set("long", "��������������᷿������˯��һ��Ů�ӣ���Χվ�����򸮵ĵ��ӺͼҶ���\n"); 
                obroom->set("create_time", time());
                ob1 = new("/clone/skybook14/lianchengjue/npc/qifang");
                ob1->move(obroom);              
                me->move(obroom);
        break;

        case 5: // �η� ����
                obroom = new("/clone/skybook14/sky14room");
                obroom->set_name(HIG + "�᷿" + NOR, ({ "xiaomaowu" }));
              //obroom>set("long", "�����Ǳ����ǵĵذ��Ŵ�֡��ֵ�����������������֣������������ﲻ����\n������ƥ�������С�\n",");  
                obroom->set("long", "�����Ǿ��ݴ��Σ�ר�Ź�Ѻ�ط������ܳ���Ѭ�죬������ʪ��\n"); 
                obroom->set("create_time", time());
                ob1 = new("/clone/skybook14/lianchengjue/npc/dingdian");
                ob1->move(obroom);
                me->move(obroom);
        break;

        default:return;
        }
        
        switch(obx)
        {
        case 1:return ob1;
        case 2:return ob2;
        case 3:return ob3;
        case 4:return ob4;
        case 5:return ob5;
        case 6:return ob6;
        case 7:return ob7;
        case 8:return ob8;                      
        default:return ob1;
        }
}

// ģ��Ի���ɺ���õ���ں�����ִ�к������� me������ң�flag �����ţ����ڷֱ治ͬ�Ĵ���
void dialog_end(object me, int flag)
{
        object ob;
                
        if (! objectp(me))return;
        
        //tell_object(me, "flag = " + sprintf("%d", flag) + "\n");
                        
        switch(flag)
        {
        case 1:
                ob = move_to_room(me, 1, 1);
                DIALOG_D->start_dialog(ob, me, sBookMsg2, 0, 5);
                return;
        break;

        case 5:
                me->set("skybook14/���Ǿ�/������", 5);
                me->set_player_skill("tangshi-jian", 1);
                me->set("skybook14/���Ǿ�/��ǰ����", "����ʫ����������500����������ɺ�����skybook start ���Ǿ���");
                
                return;
        break;

        case 10:
                me->set("skybook14/���Ǿ�/������", 10);
                me->set("skybook14/���Ǿ�/��ǰ����", "��ʦ���ݷ��д����գ�fight qi fang����");

                return;
        break;

        case 15:
                me->set("skybook14/���Ǿ�/����״̬", 0);
                me->set("skybook14/���Ǿ�/������", 15);
                me->set("skybook14/���Ǿ�/��ǰ����", "�Ѽ��׺�Ƥ200�š�");
                me->set("skybook14/���Ǿ�/��ǰ�½�", "��1��");
                return;
        break;

        case 20:
                me->set("skybook14/���Ǿ�/����״̬", 1);
                me->set("skybook14/���Ǿ�/������", 20);
                me->set("skybook14/���Ǿ�/��ǰ����", "׼���ú��׼��ǰ�������򸮰ɣ�skybook start ���Ǿ���");
                me->set("skybook14/���Ǿ�/��ǰ�½�", "��1��");
                return;
        break;
        
        case 25:
                me->set("skybook14/���Ǿ�/����״̬", 0);
                me->set("skybook14/���Ǿ�/������", 25);
                me->set("skybook14/���Ǿ�/��ǰ����", "���ܴ����ͨ");
                me->set("skybook14/���Ǿ�/��ǰ�½�", "��1��");

                ob = environment(me);
                
                return;
        break;  
        
        case 30:
                ob = move_to_room(me, 4, 1);
                me->set("skybook14/���Ǿ�/����״̬", 0);
                me->set("skybook14/���Ǿ�/������", 30);
                me->set("skybook14/���Ǿ�/��ǰ����", "����start skybook ���Ǿ� ��������");

                return;
        break;          

        case 35:
                ob = move_to_room(me, 5, 1);
                me->set("skybook14/���Ǿ�/��ǰ�½�", "��2��");
                me->set("skybook14/���Ǿ�/����״̬", 0);
                me->set("skybook14/���Ǿ�/��ǰ����", "����start skybook ���Ǿ� ��������");
                me->set("skybook14/���Ǿ�/������", 35);

                return;
        break;          
        default:return;
        }
}

// ���� /cmds/usr/skybook.c���ã���ʼ��������
void startbook(object me, string sBook)
{
        int nQuest; // ��ǰ������
        string sZhangjie; // ��ǰ�½�
        object ob, ob2;

        sZhangjie = me->query("skybook14/" + sBook + "/��ǰ�½�");
        nQuest = me->query("skybook14/" + sBook + "/������");

        switch(nQuest)
        {
        case 1: // ����
                DIALOG_D->start_dialog4(this_object(), me, sBookMsg1, 0, 1);
                return;
        break;
        
        case 5:// ������ʫ������500LV
                if (me->query_skill("tangshi-jian", 1) < 500)
                {
                        tell_object(me, me->query("skybook14/���Ǿ�/��ǰ����") + "\n");
                        return;
                }
                
                ob = move_to_room(me, 1, 1);

                DIALOG_D->start_dialog(ob, me, sBookMsg3, 0, 10);
                
                return;
        break;

        case 10: // �д����ݷ���
                if (me->query("skybook14/���Ǿ�/����״̬") != 1)
                {       
                        move_to_room(me, 1, 1); // ����δ��ɣ����´��ͷ���

                        tell_object(me, me->query("skybook14/���Ǿ�/��ǰ����") + "\n");
                        return;
                }

                ob = move_to_room(me, 1, 1);

                DIALOG_D->start_dialog(ob, me, sBookMsg4, 0, 15);

                return;
        break;

        case 15: // �Ѽ���200�ź���Ƥ��
                if (me->query("skybook14/���Ǿ�/����״̬") != 1)
                {       
                        object ob_hlp;
                        // ����Ƿ���200�ź���Ƥ���������۳�
                        if (! objectp(ob_hlp = present("baihu pi", me)))
                        {
                                tell_object(me, me->query("skybook14/���Ǿ�/��ǰ����") + "\n");
                                return;
                        }

                        if (base_name(ob_hlp) != "/clone/quarry/item/lipi2")
                                return;
        
                        if (ob_hlp->query_amount() >= 200)
                        {
                                ob_hlp->add_amount(-200);
                                if (ob_hlp->query_amount() < 1)destruct(ob_hlp);
                                tell_object(me, HIG "�����ɣ�\n" NOR); 
                        }
                        else
                        {
                                tell_object(me, me->query("skybook14/���Ǿ�/��ǰ����") + "\n");
                                return;
                        }
                        
                        me->set("skybook14/���Ǿ�/����״̬", 1);
                }

                ob = move_to_room(me, 1, 2);

                DIALOG_D->start_dialog(ob, me, sBookMsg5, 0, 20);

                return;

        break;
        
        case 20: // ǰ��������
                
                ob = move_to_room(me, 2, 1);

                DIALOG_D->start_dialog(ob, me, sBookMsg6, 0, 25);

                return;
        break;  
        
        case 25: // ���ܴ����ͨ
                                        
                if (me->query("skybook14/���Ǿ�/����״̬") != 1)
                {
                        ob = move_to_room(me, 2, 1); // ����δ��ɣ����´��ͷ���

                        tell_object(me, me->query("skybook14/���Ǿ�/��ǰ����") + "\n");
                        return;
                }
                
                // ������
                ob = move_to_room(me, 3, 1);

                DIALOG_D->start_dialog4(this_object(), me, sBookMsg7, 0, 30);

                return;

        break;
        
        case 30: // ׷��Ӱ���᷿

                // ������
                ob = move_to_room(me, 4, 1);

                DIALOG_D->start_dialog(ob, me, sBookMsg8, 0, 35);

                return;

        break;
                        
        case 35: // ���᷿������

                // ������
                ob = move_to_room(me, 5, 1);

                //DIALOG_D->start_dialog4(ob, me, sBookMsg8, 0, 40);

                return;

        break;

        default:
                tell_object(me, HIY "���� skybook cha ���Ǿ� �鿴��ǰ���������\n" NOR);
                return;
        }
        
        
        
}
