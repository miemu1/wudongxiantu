// Room: /city/qianzhuang.c
inherit ROOM;

object N_b();
object N();
object R_b();
object R();
object UR_potential();
object UR_yuanbao();
object UR_yuanbao_2();
object SR_b();
object SR();
object SSR_b();
object SSR();
object UUR();
void create()
{
	set("short", "Ǯׯ");
	set("long", @LONG
����һ�����ֺŵ�Ǯׯ�����м��������ʷ����ȫ�����ض��зֵꡣ����
�е���Ʊ�����ǳ��ã�ͨ��ȫ����
    �ڶ����ǽ�Ϲ��˿�����(paizi)��
LONG );
	set("no_fight", 1);
	set("exits", ([
		"east" : __DIR__"beidajie1",
	]));
	set("item_desc", ([
		"�����ӡ�" : "��Ǯׯ�ṩ���·���\n"
		ZJOBACTS2+ZJMENUF(3,3,8,30)"��Ǯ:cun"ZJSEP"ȡǮ:qu"ZJSEP"����:check\n",
		"�齱��" : "����һ̨��ʦ���Ļ���������Գ鵽�ܶ�Ľ�Ʒ��\n",
	]) );
    set("action_list", ([
		HIY"����齱(20��ʯ)"NOR : "chou -yuanbao",
	  // HIY"����齱(30��ȯ)"NOR : "chou -jifeng", 	
	  //	HIW"��ɫŤ��(10��Ʊ)"NOR : "chou -cash",
//MAG"��ɫŤ��(3000Ǳ��)"NOR : "chou -potential",
	]));
	set("objects", ([
		__DIR__"npc/qian" : 1
	]));
	setup();
}
void init()
{
	add_action("do_chou", "chou");
}
int do_chou(string arg) {
    object gift, money, me;
    int i, j,number,p;
    mapping my;
    me = this_player();
       if (!arg) return notify_fail("��ҪҪ���Ǹ��齱��\n");
       
       if ((int)me->query("max_qi")>10000000) return notify_fail("����Ѫ̫��û�취�齱��\n");

        if (arg == "-yuanbao") {
            if (me->query("yuanbao") >= 20) {
                me->add("yuanbao", -20);
                me->add("nd_yuanbai", 1);
                tell_object(me, HIM"�㻨��20��ʯ��������"HIY"����齱��\n"NOR);
            } else {
                return notify_fail("�����ϵ���ʯ����20��\n");
            }
          i=random(10000);
          if(i<1){
          gift=UUR();
          log_file("new_gift/nd_yuanbao", sprintf("%s��%s(%s)����ʯ�齱��%d�γ鵽%s,���ֵ��%d��\n",
				ctime(time()),me->query("name"),me->query("id"),me->query("nd_yuanbao"),gift->name(),i));
          call_out("b",1,gift);
          me->set_temp("nd",1); 
          }else if(i<10){
          gift=UR_yuanbao();
          log_file("new_gift/nd_yuanbao", sprintf("%s��%s(%s)����ʯ�齱��%d�γ鵽%s,���ֵ��%d��\n",
				ctime(time()),me->query("name"),me->query("id"),me->query("nd_yuanbao"),gift->name(),i));
          call_out("b",1,gift);
          me->set_temp("nd",1);
          }else if(i<500){
          gift=SSR();
          log_file("new_gift/nd_yuanbao", sprintf("%s��%s(%s)����ʯ�齱��%d�γ鵽%s,���ֵ��%d��\n",
				ctime(time()),me->query("name"),me->query("id"),me->query("nd_yuanbao"),gift->name(),i));
          call_out("b",1,gift);
          me->set_temp("nd",1);
          }else if(i<3000){//������
          gift=SR();
          
          call_out("a",1,gift);
          me->set_temp("nd",1);
          }else if(i<6000){
          gift=R();
          call_out("a",1,gift);
          me->set_temp("nd",1);
          }else{
          gift=N();
          call_out("a",1,gift);
          me->set_temp("nd",1);               
          }
          return 1;//�齱���
        } else if (arg == "-jifeng") {
            if (me->query("jifeng") >= 30) {
                me->add("jifeng", -30);
                me->add("nd_jifeng", 1);
                tell_object(me, HIM"�㻨��30��ȯ��������"HIY "����齱��\n"NOR);
            } else {
                return notify_fail("�����ϵĵ�ȯ����30��\n");
            }
          i=random(10000);
          if(i<1){
          gift=UUR();
          log_file("new_gift/nd_jifeng", sprintf("%s��%s(%s)�õ�ȯ�齱��%d�γ鵽%s,���ֵ��%d��\n",
				ctime(time()),me->query("name"),me->query("id"),me->query("nd_yuanbao_2"),gift->name(),i));
          call_out("b",1,gift);
          me->set_temp("nd",1); 
          }else if(i<10){
          gift=UR_yuanbao_2();
          log_file("new_gift/nd_jifeng", sprintf("%s��%s(%s)�õ�ȯ�齱��%d�γ鵽%s,���ֵ��%d��\n",
				ctime(time()),me->query("name"),me->query("id"),me->query("nd_yuanbao_2"),gift->name(),i));
          call_out("b",1,gift);
          me->set_temp("nd",1);
          }else if(i<500){
          gift=SSR_b();
          log_file("new_gift/nd_jifeng", sprintf("%s��%s(%s)�õ�ȯ�齱��%d�γ鵽%s,���ֵ��%d��\n",
				ctime(time()),me->query("name"),me->query("id"),me->query("nd_yuanbao_2"),gift->name(),i));
          call_out("b",1,gift);
          me->set_temp("nd",1);
          }else if(i<3000){//������
          gift=SR_b();
          call_out("a",1,gift);
          me->set_temp("nd",1);
          }else if(i<6000){
          gift=R_b();
          call_out("a",1,gift);
          me->set_temp("nd",1);
          }else{
          gift=N_b();
          call_out("a",1,gift);
          me->set_temp("nd",1);
            }
           return 1;//�齱���
           } else if (arg == "-cash") {
           if (money = present("cash", me)) {
            number = money->query_amount();
            if (number >= 10) {
                money->add_amount(-10);
                me->add("nd_cash", 1);
                tell_object(me, HIM"�㻨��ʮ������Ʊ��������"HIW"��ɫ�齱��\n"NOR);
            } else { //������Ʊȴ��������һ��
                return notify_fail("�����ϵ���Ʊ����ʮ��\n");
            }
        }else{    
        return notify_fail("�����ϵ�û����Ʊ\n");        
       }
        
        i=random(100);
        if(i<1){
        gift=new("/clone/shangren/bai");
        call_out("a",1,gift);
        me->set_temp("nd",1);
        }else if(i<30){
        gift=R_b();
        call_out("a",1,gift);
        me->set_temp("nd",1);
        }else{
        gift=N_b();
        call_out("a",1,gift);
        me->set_temp("nd",1);
        }
   
         }else if(arg == "-potential"){
           my =me->query_entire_dbase();
                p=my["potential"];
              //  tell_object(me, "��ǰǱ�ܣ�"+p);
           if (p>= 3000) {
                me->add("potential", -3000);
                me->add("nd_potential", 1);
                tell_object(me, HIM"�㻨��3000Ǳ�ܣ�������"MAG "��ɫ�齱��\n"NOR);
            } else {
                return notify_fail("���Ǳ�ܲ���3000\n");
            }
      
      i=random(100);
        if(i<1){
        gift=UR_potential();
        call_out("a",1,gift);
        me->set_temp("nd",1);
        }else if(i<30){
        gift=SR_b();
        call_out("a",1,gift);
        me->set_temp("nd",1);
        }else if(i<60){
        gift=R_b();
        call_out("a",1,gift);
        me->set_temp("nd",1);
        }else{
        gift=N_b();
        call_out("a",1,gift);
        me->set_temp("nd",1);
        }  
    }
    return 1;
}
object N_b(){//N����
object ob;
string *list = ({
"/clone/aaa/vip2/book_tianfu",//�츳��
"/clone/aaa/vip2/book_wuliang",//����
"/clone/aaa/vip2/dan_chongmai1",//�³�
"/clone/aaa/vip2/jinsha",//��ɳ
"/clone/aaa/vip2/putao",//����
"/clone/aaa/vip2/dan_zhengqi",//����
"/clone/aaa/vip2/dan_xieqi",//а��
"/clone/aaa/vip2/dan_chongmai2",//������
}); 
 ob=new(list[random(sizeof(list))]);
 return ob;
}


object N(){//N������
object ob;
string *list = ({
"/clone/aaa/book_tianfu",//�츳��
"/clone/aaa/book_wuliang",//����
"/clone/aaa/dan_chongmai1",//�³�
"/clone/aaa/jinsha",//��ɳ
"/clone/aaa/putao",//����
"/clone/aaa/dan_zhengqi",//����
"/clone/aaa/dan_xieqi",//а��
"/clone/aaa/dan_chongmai3",//������
}); 
 ob=new(list[random(sizeof(list))]);
 return ob;
}



object R(){//R������
object ob;
string *list = ({
"/clone/aaa/fushougao",//����
//"/clone/aaa/hua5",//�����
"/clone/aaa/dan_chongmai2",//�г�
"/clone/aaa/dan_chongmai2",//��֥
"/clone/aaa/lingzhi2",//С����
}); 
 ob=new(list[random(sizeof(list))]);
 return ob;
}


int a(object gift){
object me = this_player();
tell_object(me,"����齱�п�Ƭ������裬����������һ�ſ�Ƭ������һ��\n");
call_out("a_b",1,gift);
}
void b(object gift){
object me = this_player();
tell_object(me,"����齱�п�Ƭ������裬����������һ�ſ�Ƭ������һ��\n");
call_out("b_b",1,gift);
}
void a_b(object gift){
object me = this_player();
gift->move(me);
tell_object(me,"��үү�����̣�������һ�����տ�"+gift->name()+"\n");
me->delete_temp("nd");
}
void b_b(object gift){
object me = this_player();
gift->move(me);
tell_object(me,"��үү�����̣�������һ�����տ�"+gift->name()+"\n");
//CHANNEL_D->do_channel(this_object(), "rumor",me->name()+"�ڳ齱��������"+gift->name());
me->delete_temp("nd");
}


object R_b(){//R����
object ob;
string *list = ({
"/clone/aaa/vip2/fushougao",//����
"/clone/aaa/vip2/hua5",//�����
"/clone/aaa/vip2/dan_chongmai2",//�г�
"/clone/aaa/vip2/lingzhi",//��֥
"/clone/aaa/vip2/lingzhi2",//С����
}); 
 ob=new(list[random(sizeof(list))]);
 return ob;
}




object UR_potential(){//UR��Ǳ��
object ob;
string *list = ({
"/clone/shangren/hetian",//������
"/clone/aaa/vip2/dan_jiuzhuan",//��ת
"/clone/aaa/vip2/putao1",//����
}); 
 ob=new(list[random(sizeof(list))]);
 return ob;
}



object SSR(){//SSR������
object ob;
string *list = ({
"/clone/aaa/dan_con",//ϴ��
"/clone/aaa/dan_dex",//���
"/clone/aaa/dan_str",//����
"/clone/aaa/dan_int",//����
"/clone/aaa/dan_chongmai4",//����
"/clone/aaa/yanzhi",//��֬
"/clone/aaa/avipcard",//�¿�
"/clone/aaa/ling_wolong",//����
"/clone/aaa/jinpiao",//��Ʊ
}); 
 ob=new(list[random(sizeof(list))]);
 return ob;
}


object SSR_b(){//SSR����
object ob;
string *list = ({
"/clone/aaa/vip2/dan_con",//ϴ��
"/clone/aaa/vip2/dan_dex",//���
"/clone/aaa/vip2/dan_str",//����
"/clone/aaa/vip2/dan_int",//����
"/clone/aaa/vip2/dan_chongmai4",//����
"/clone/aaa/vip2/yanzhi",//��֬
"/clone/aaa/vip2/aaaacard",//�¿�
"/clone/aaa/vip2/ling_wolong",//����
"/clone/aaa/vip2/jinpiao",//��Ʊ
}); 
 ob=new(list[random(sizeof(list))]);
 return ob;
}





object UR_yuanbao(){//UR������
object ob;
string *list = ({
"/clone/aaa/dan_jiuzhuan",//��ת
"/clone/aaa/butian",//����
"/clone/aaa/tiancs",//����
"/clone/aaa/card_name",//������
"/clone/aaa/tianxingdan",//���Ե�
"/clone/shangren/lantian",//����
"/clone/aaa/putao1",//�¿�
"/clone/aaa/xidianka",//ϴ��
}); 
 ob=new(list[random(sizeof(list))]);
 return ob;
}



object UR_yuanbao_2(){//UR������
object ob;
string *list = ({
"/clone/aaa/vip2/dan_jiuzhuan",//��ת
"/clone/aaa/vip2/butian",//����
"/clone/aaa/vip2/tiancs",//����
"/clone/aaa/hua",//����
"/clone/aaa/vip2/card_name",//������
"/clone/aaa/vip2/tianxingdan",//���Ե�
"/clone/shangren/lantian",//����
"/clone/aaa/vip2/putao1",//�¿�
}); 
 ob=new(list[random(sizeof(list))]);
 return ob;
}




object UUR(){//UUR������
object ob;
string *list = ({
"/clone/shangren/book_mengzi",//��
"/clone/shangren/guigu",//���
}); 
 ob=new(list[random(sizeof(list))]);
 return ob;
}








object SR_b(){//SR����
object ob;
string *list = ({
"/clone/shangren/putao3",//���Ѹ�
"/clone/aaa/vip2/tianxiang",//����
"/clone/aaa/vip2/dan_chongmai3",//�ϳ�
"/clone/aaa/vip2/dan_chongmai2",//�г�
}); 
 ob=new(list[random(sizeof(list))]);
 return ob;
}







object SR(){//SR������
object ob;
string *list = ({
"/clone/putao3",//���Ѹ�
"/clone/aaa/tianxiang",//����
"/clone/aaa/dan_chongmai3",//�ϳ�
"/clone/aaa/dan_chongmai2",//�г�
}); 
 ob=new(list[random(sizeof(list))]);
 return ob;
}
