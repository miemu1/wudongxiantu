// time.c

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string str;
	    object obj,ob,obj1,obj2,obj3,obj4;
        int count,mengxin;
        string a;
		me = this_player();
	if(!arg)
	{
		str = ZJOBLONG"����ƺ���ǰ���ƺŽ��棺\n";
		str += ZJOBACTS2+ZJMENUF(1,1,9,29);
//		str += HIW"���������"NOR":jihuo1"ZJSEP""HIG"��������"NOR":jihuo2";
	str += WHT"[����]"NOR"["+((me->query("titles/����"))?HIG"�Ѽ���"NOR:HIR"δ����"NOR)+"]["+((me->query("title")=="����")?HIG"�����"NOR:HIR"δ���"NOR)+"]+ZJBR+["+((me->query("titles/����"))?HIG"�Ѽ���"NOR:HIR"δ����"NOR)+"]:chengh ����"ZJSEP;
//	str += WHT"[��������]"NOR"["+((me->query("jihuom/s2")>=1)?HIG"����ȡ"NOR:HIR"δ��ȡ"NOR)+"]:jihuo2"ZJSEP;

	}
	

	message("vision", str+"\n", me);

			if(me->is_fighting())
	{
		tell_object(me,"��������ս����\n");
		return 1;
	}
		if(me->is_busy())
	{
		tell_object(me,"����æ��\n");
		return 1;
	}
	switch (arg) {
	  case "����" :
			if(!me->query("titles/����")&&me->query_skill("force")>=200)
			{
			me->add("int",1);
			me->add("dex",1);
			me->add("con",1);
			me->add("str",1);
			me->add("max_qi",200);
			me->set("titles/����",1);
//				me->set("zhanlinglq/s1",1);
				tell_object(me,"�ƺ���ȡ�ɹ���\n");
				return 1;
			}else
	{message_vision(HIG"�㻹û�дﵽ�ɾ���ȡҪ�󡢻������Ѿ���ȡ���ˡ�"NOR"\n", me);
	    return 1;}
		break;
	  case "1" :
	  {
		str = ZJOBLONG"����ƺ���ǰ���ƺŽ��棺\n";
		str += ZJOBACTS2+ZJMENUF(1,1,7,31);
//		str += HIW"���������"NOR":jihuo1"ZJSEP""HIG"��������"NOR":jihuo2";
	str += HIC"[����]"NOR"["+((me->query("titles/����"))?WHT"�Ѽ���"NOR:WHT"δ����"NOR)+"]["+((me->query("title")=="����")?HIG"�����"NOR:WHT"δ���"NOR)+"]																							 "WHT"����Ҫ��"HIR"�����ڹ�>200"NOR"																				  	"WHT"������"CYN"������ά+1����Ѫ+200"NOR":chengh ����"ZJSEP;
	str += HIC"[����]"NOR"["+((me->query("titles/����"))?WHT"�Ѽ���"NOR:WHT"δ����"NOR)+"]["+((me->query("title")=="����")?HIG"�����"NOR:WHT"δ���"NOR)+"]																							 "WHT"����Ҫ��"HIR"���Ϻ���>500"NOR"																					  "WHT"������"CYN"������ά+1����Ѫ+1000"NOR":chengh ����"ZJSEP;
	str += HIC"[��ħ]"NOR"["+((me->query("titles/��ħ"))?WHT"�Ѽ���"NOR:WHT"δ����"NOR)+"]["+((me->query("title")=="��ħ")?HIG"�����"NOR:WHT"δ���"NOR)+"]																							 "WHT"����Ҫ��"HIR"���¾Ž�>500"NOR"																					  "WHT"������"CYN"������ά+1����Ѫ+1000"NOR":chengh ��ħ"ZJSEP;
	str += HIC"[̫��]"NOR"["+((me->query("titles/̫��"))?WHT"�Ѽ���"NOR:WHT"δ����"NOR)+"]["+((me->query("title")=="̫��")?HIG"�����"NOR:WHT"δ���"NOR)+"]																						   "WHT"����Ҫ��"HIR"̫��(�񹦡�������ȭ)>500"NOR"								                "WHT"������"CYN"������ά+1����Ѫ+1000"NOR":chengh ̫��"ZJSEP;
	str += HIC"[��ʥ]"NOR"["+((me->query("titles/��ʥ"))?WHT"�Ѽ���"NOR:WHT"δ����"NOR)+"]["+((me->query("title")=="��ʥ")?HIG"�����"NOR:WHT"δ���"NOR)+"]																						   "WHT"����Ҫ��"HIR"Ǭ����Ų�ơ�������>500"NOR"												"WHT"������"CYN"������ά+1����Ѫ+1000"NOR":chengh ��ʥ"ZJSEP;
	str += HIC"[����]"NOR"["+((me->query("titles/����"))?WHT"�Ѽ���"NOR:WHT"δ����"NOR)+"]["+((me->query("title")=="����")?HIG"�����"NOR:WHT"δ���"NOR)+"]																						   "WHT"����Ҫ��"HIR"��ղ����塢�����ķ�>500"NOR"												"WHT"������"CYN"������ά+1����Ѫ+1000"NOR":chengh ����"ZJSEP;
	str += HIC"[����]"NOR"["+((me->query("titles/����"))?WHT"�Ѽ���"NOR:WHT"δ����"NOR)+"]["+((me->query("title")=="����")?HIG"�����"NOR:WHT"δ���"NOR)+"]																						   "WHT"����Ҫ��"HIR"���񹦡��ƻ���ľ>500"NOR"								                                            "WHT"������"CYN"������ά+1����Ѫ+1000"NOR":chengh ����"ZJSEP;
	str += HIC"[����]"NOR"["+((me->query("titles/����"))?WHT"�Ѽ���"NOR:WHT"δ����"NOR)+"]["+((me->query("title")=="����")?HIG"�����"NOR:WHT"δ���"NOR)+"]																							 "WHT"����Ҫ��"HIR"����д��>500"NOR"															                        "WHT"������"CYN"������ά+1����Ѫ+1000"NOR":chengh ����"ZJSEP;
	str += HIC"[��ڤ��]"NOR"["+((me->query("titles/��ڤ��"))?WHT"�Ѽ���"NOR:WHT"δ����"NOR)+"]["+((me->query("title")=="��ڤ��")?HIG"�����"NOR:WHT"δ���"NOR)+"]																						 "WHT"����Ҫ��"HIR"�貨΢������ڤ��>500"NOR"									                                        "WHT"������"CYN"������ά+1����Ѫ+1000"NOR":chengh ��ڤ��"ZJSEP;
	str += HIC"[��Ľ��]"NOR"["+((me->query("titles/��Ľ��"))?WHT"�Ѽ���"NOR:WHT"δ����"NOR)+"]["+((me->query("title")=="��Ľ��")?HIG"�����"NOR:WHT"δ���"NOR)+"]																						 "WHT"����Ҫ��"HIR"��ת����>500"NOR"															                        "WHT"������"CYN"������ά+1����Ѫ+1000"NOR":chengh ��Ľ��"ZJSEP;
	str += HIC"[������]"NOR"["+((me->query("titles/������"))?WHT"�Ѽ���"NOR:WHT"δ����"NOR)+"]["+((me->query("title")=="������")?HIG"�����"NOR:WHT"δ���"NOR)+"]																						 "WHT"����Ҫ��"HIR"̫����>500"NOR"															                          "WHT"������"CYN"������ά+1����Ѫ+1000"NOR":chengh ������"ZJSEP;
	str += HIC"[��ҹ����]"NOR"["+((me->query("titles/��ҹ����"))?WHT"�Ѽ���"NOR:WHT"δ����"NOR)+"]["+((me->query("title")=="��ҹ����")?HIG"�����"NOR:WHT"δ���"NOR)+"]																				 "WHT"����Ҫ��"HIR"��а����>500"NOR"															                        "WHT"������"CYN"������ά+1����Ѫ+1000"NOR":chengh ��ҹ����"ZJSEP;
	str += HIC"[�̺�����]"NOR"["+((me->query("titles/�̺�����"))?WHT"�Ѽ���"NOR:WHT"δ����"NOR)+"]["+((me->query("title")=="�̺�����")?HIG"�����"NOR:WHT"δ���"NOR)+"]																				 "WHT"����Ҫ��"HIR"�̲��񹦡��̺�������>500"NOR"					                            "WHT"������"CYN"������ά+1����Ѫ+1000"NOR":chengh �̺�����"ZJSEP;
	str += HIC"[����֮��]"NOR"["+((me->query("titles/����֮��"))?WHT"�Ѽ���"NOR:WHT"δ����"NOR)+"]["+((me->query("title")=="����֮��")?HIG"�����"NOR:WHT"δ���"NOR)+"]																				 "WHT"����Ҫ��"HIR"���������>500"NOR"													                         "WHT"������"CYN"������ά+1����Ѫ+1000"NOR":chengh ����֮��"ZJSEP;
	str += HIC"[ѩ�Ϸɺ�]"NOR"["+((me->query("titles/ѩ�Ϸɺ�"))?WHT"�Ѽ���"NOR:WHT"δ����"NOR)+"]["+((me->query("title")=="ѩ�Ϸɺ�")?HIG"�����"NOR:WHT"δ���"NOR)+"]																				 "WHT"����Ҫ��"HIR"�����񹦡����ҵ���>500"NOR"												  "WHT"������"CYN"������ά+1����Ѫ+1000"NOR":chengh ѩ�Ϸɺ�"ZJSEP;
	str += HIC"[��Ӱ����]"NOR"["+((me->query("titles/��Ӱ����"))?WHT"�Ѽ���"NOR:WHT"δ����"NOR)+"]["+((me->query("title")=="��Ӱ����")?HIG"�����"NOR:WHT"δ���"NOR)+"]																				 "WHT"����Ҫ��"HIR"�����񹦡�Ʈ����>500"NOR"												  "WHT"������"CYN"������ά+1����Ѫ+1000"NOR":chengh ��Ӱ����"ZJSEP;
	str += HIC"[���ɵй�]"NOR"["+((me->query("titles/���ɵй�"))?WHT"�Ѽ���"NOR:WHT"δ����"NOR)+"]["+((me->query("title")=="���ɵй�")?HIG"�����"NOR:WHT"δ���"NOR)+"]																				 "WHT"����Ҫ��"HIR"��ʯ����>9999999"NOR"											                                "WHT"������"CYN"������ά+1����Ѫ+1000"NOR":chengh ���ɵй�"ZJSEP;
	str += HIC"[������]"NOR"["+((me->query("titles/������"))?WHT"�Ѽ���"NOR:WHT"δ����"NOR)+"]["+((me->query("title")=="������")?HIG"�����"NOR:WHT"δ���"NOR)+"]																				 "WHT"����Ҫ��"HIR"Ů����ò>50"NOR"											                                "WHT"������"CYN"������ά+1����Ѫ+1000"NOR":chengh ������"ZJSEP;
	str += HIC"[İ�Ͼ���]"NOR"["+((me->query("titles/İ�Ͼ���"))?WHT"�Ѽ���"NOR:WHT"δ����"NOR)+"]["+((me->query("title")=="İ�Ͼ���")?HIG"�����"NOR:WHT"δ���"NOR)+"]																				 "WHT"����Ҫ��"HIR"������ò>50"NOR"											                                "WHT"������"CYN"������ά+1����Ѫ+1000"NOR":chengh İ�Ͼ���"ZJSEP;
	str += HIC"[��������]"NOR"["+((me->query("titles/��������"))?WHT"�Ѽ���"NOR:WHT"δ����"NOR)+"]["+((me->query("title")=="��������")?HIG"�����"NOR:WHT"δ���"NOR)+"]																				 "WHT"����Ҫ��"HIR"��ѧ��������������>500"NOR"											                                "WHT"������"CYN"������ά+1����Ѫ+1000"NOR":chengh ��������"ZJSEP;
	str += HIC"[��������]"NOR"["+((me->query("titles/��������"))?WHT"�Ѽ���"NOR:WHT"δ����"NOR)+"]["+((me->query("title")=="��������")?HIG"�����"NOR:WHT"δ���"NOR)+"]																				 "WHT"����Ҫ��"HIR"��������>100"NOR"											                                "WHT"������"CYN"������ά+1����Ѫ+1000"NOR":chengh ��������"ZJSEP;
	str += HIC"[һ������]"NOR"["+((me->query("titles/һ������"))?WHT"�Ѽ���"NOR:WHT"δ����"NOR)+"]["+((me->query("title")=="һ������")?HIG"�����"NOR:WHT"δ���"NOR)+"]																				 "WHT"����Ҫ��"HIR"���ɽ���>500"NOR"															                        "WHT"������"CYN"������ά+1����Ѫ+1000"NOR":chengh һ������"ZJSEP;



	message("vision", str+"\n", me);
				return 1;
			}
		break;
	  case "����" :
			if(!me->query("titles/����")&&me->query_skill("freezing-force")>=500)
			{
			me->add("int",1);
			me->add("dex",1);
			me->add("con",1);
			me->add("str",1);
			me->add("max_qi",1000);
			me->set("titles/����",1);
//				me->set("zhanlinglq/s1",1);
				tell_object(me,"�ƺ���ȡ�ɹ���\n");
				return 1;
			}else
	{message_vision(HIG"�㻹û�дﵽ�ɾ���ȡҪ�󡢻������Ѿ���ȡ���ˡ�"NOR"\n", me);
	    return 1;}
		break;
	  case "��ħ" :
			if(!me->query("titles/��ħ")&&me->query_skill("lonely-sword")>=500)
			{
			me->add("int",1);
			me->add("dex",1);
			me->add("con",1);
			me->add("str",1);
			me->add("max_qi",1000);
			me->set("titles/��ħ",1);
//				me->set("zhanlinglq/s1",1);
				tell_object(me,"�ƺ���ȡ�ɹ���\n");
				return 1;
			}else
	{message_vision(HIG"�㻹û�дﵽ�ɾ���ȡҪ�󡢻������Ѿ���ȡ���ˡ�"NOR"\n", me);
	    return 1;}
		break;
	  case "̫��" :
			if(!me->query("titles/̫��")&&me->query_skill("taiji-shengong")>=500&&me->query_skill("taiji-jian")>=500&&me->query_skill("taiji-quan")>=500)
			{
			me->add("int",1);
			me->add("dex",1);
			me->add("con",1);
			me->add("str",1);
			me->add("max_qi",1000);
			me->set("titles/̫��",1);
//				me->set("zhanlinglq/s1",1);
				tell_object(me,"�ƺ���ȡ�ɹ���\n");
				return 1;
			}else
	{message_vision(HIG"�㻹û�дﵽ�ɾ���ȡҪ�󡢻������Ѿ���ȡ���ˡ�"NOR"\n", me);
	    return 1;}
		break;
	  case "��ʥ" :
			if(!me->query("titles/��ʥ")&&me->query_skill("qiankun-danuoyi")>=500&&me->query_skill("jiuyang-shengong")>=500)
			{
			me->add("int",1);
			me->add("dex",1);
			me->add("con",1);
			me->add("str",1);
			me->add("max_qi",1000);
			me->set("titles/��ʥ",1);
//				me->set("zhanlinglq/s1",1);
				tell_object(me,"�ƺ���ȡ�ɹ���\n");
				return 1;
			}else
	{message_vision(HIG"�㻹û�дﵽ�ɾ���ȡҪ�󡢻������Ѿ���ȡ���ˡ�"NOR"\n", me);
	    return 1;}
		break;
	  case "����" :
			if(!me->query("titles/����")&&me->query_skill("jingang-buhuaiti")>=500&&me->query_skill("buddhism")>=500)
			{
			me->add("int",1);
			me->add("dex",1);
			me->add("con",1);
			me->add("str",1);
			me->add("max_qi",1000);
			me->set("titles/����",1);
//				me->set("zhanlinglq/s1",1);
				tell_object(me,"�ƺ���ȡ�ɹ���\n");
				return 1;
			}else
	{message_vision(HIG"�㻹û�дﵽ�ɾ���ȡҪ�󡢻������Ѿ���ȡ���ˡ�"NOR"\n", me);
	    return 1;}
		break;
	  case "����" :
			if(!me->query("titles/����")&&me->query_skill("literate")>=500)
			{
			me->add("int",1);
			me->add("dex",1);
			me->add("con",1);
			me->add("str",1);
			me->add("max_qi",1000);
			me->set("titles/����",1);
//				me->set("zhanlinglq/s1",1);
				tell_object(me,"�ƺ���ȡ�ɹ���\n");
				return 1;
			}else
	{message_vision(HIG"�㻹û�дﵽ�ɾ���ȡҪ�󡢻������Ѿ���ȡ���ˡ�"NOR"\n", me);
	    return 1;}
		break;
	  case "����" :
			if(!me->query("titles/����")&&me->query_skill("mingyu-gong")>=500&&me->query_skill("yihua-jiemu")>=500)
			{
			me->add("int",1);
			me->add("dex",1);
			me->add("con",1);
			me->add("str",1);
			me->add("max_qi",1000);
			me->set("titles/����",1);
//				me->set("zhanlinglq/s1",1);
				tell_object(me,"�ƺ���ȡ�ɹ���\n");
				return 1;
			}else
	{message_vision(HIG"�㻹û�дﵽ�ɾ���ȡҪ�󡢻������Ѿ���ȡ���ˡ�"NOR"\n", me);
	    return 1;}
		break;
	  case "��ڤ��" :
			if(!me->query("titles/��ڤ��")&&me->query_skill("beiming-shengong")>=500&&me->query_skill("lingbo-weibu")>=500)
			{
			me->add("int",1);
			me->add("dex",1);
			me->add("con",1);
			me->add("str",1);
			me->add("max_qi",1000);
			me->set("titles/��ڤ��",1);
//				me->set("zhanlinglq/s1",1);
				tell_object(me,"�ƺ���ȡ�ɹ���\n");
				return 1;
			}else
	{message_vision(HIG"�㻹û�дﵽ�ɾ���ȡҪ�󡢻������Ѿ���ȡ���ˡ�"NOR"\n", me);
	    return 1;}
		break;
	  case "��Ľ��" :
			if(!me->query("titles/��Ľ��")&&me->query_skill("douzhuan-xingyi")>=500)
			{
			me->add("int",1);
			me->add("dex",1);
			me->add("con",1);
			me->add("str",1);
			me->add("max_qi",1000);
			me->set("titles/��Ľ��",1);
//				me->set("zhanlinglq/s1",1);
				tell_object(me,"�ƺ���ȡ�ɹ���\n");
				return 1;
			}else
	{message_vision(HIG"�㻹û�дﵽ�ɾ���ȡҪ�󡢻������Ѿ���ȡ���ˡ�"NOR"\n", me);
	    return 1;}
		break;
	  case "������" :
			if(!me->query("titles/������")&&me->query_skill("taixuan-gong")>=500)
			{
			me->add("int",1);
			me->add("dex",1);
			me->add("con",1);
			me->add("str",1);
			me->add("max_qi",1000);
			me->set("titles/������",1);
//				me->set("zhanlinglq/s1",1);
				tell_object(me,"�ƺ���ȡ�ɹ���\n");
				return 1;
			}else
	{message_vision(HIG"�㻹û�дﵽ�ɾ���ȡҪ�󡢻������Ѿ���ȡ���ˡ�"NOR"\n", me);
	    return 1;}
		break;
	  case "��ҹ����" :
			if(!me->query("titles/��ҹ����")&&me->query_skill("pixie-jian")>=500)
			{
			me->add("int",1);
			me->add("dex",1);
			me->add("con",1);
			me->add("str",1);
			me->add("max_qi",1000);
			me->set("titles/��ҹ����",1);
//				me->set("zhanlinglq/s1",1);
				tell_object(me,"�ƺ���ȡ�ɹ���\n");
				return 1;
			}else
	{message_vision(HIG"�㻹û�дﵽ�ɾ���ȡҪ�󡢻������Ѿ���ȡ���ˡ�"NOR"\n", me);
	    return 1;}
		break;
	  case "�̺�����" :
			if(!me->query("titles/�̺�����")&&me->query_skill("bibo-shengong")>=500&&me->query_skill("bihai-chaosheng")>=500)
			{
			me->add("int",1);
			me->add("dex",1);
			me->add("con",1);
			me->add("str",1);
			me->add("max_qi",1000);
			me->set("titles/�̺�����",1);
//				me->set("zhanlinglq/s1",1);
				tell_object(me,"�ƺ���ȡ�ɹ���\n");
				return 1;
			}else
	{message_vision(HIG"�㻹û�дﵽ�ɾ���ȡҪ�󡢻������Ѿ���ȡ���ˡ�"NOR"\n", me);
	    return 1;}
		break;
	  case "����֮��" :
			if(!me->query("titles/����֮��")&&me->query_skill("longxiang")>=500)
			{
			me->add("int",1);
			me->add("dex",1);
			me->add("con",1);
			me->add("str",1);
			me->add("max_qi",1000);
			me->set("titles/����֮��",1);
//				me->set("zhanlinglq/s1",1);
				tell_object(me,"�ƺ���ȡ�ɹ���\n");
				return 1;
			}else
	{message_vision(HIG"�㻹û�дﵽ�ɾ���ȡҪ�󡢻������Ѿ���ȡ���ˡ�"NOR"\n", me);
	    return 1;}
		break;
	  case "ѩ�Ϸɺ�" :
			if(!me->query("titles/ѩ�Ϸɺ�")&&me->query_skill("hujia-daofa")>=500&&me->query_skill("lengyue-shengong")>=500)
			{
			me->add("int",1);
			me->add("dex",1);
			me->add("con",1);
			me->add("str",1);
			me->add("max_qi",1000);
			me->set("titles/ѩ�Ϸɺ�",1);
//				me->set("zhanlinglq/s1",1);
				tell_object(me,"�ƺ���ȡ�ɹ���\n");
				return 1;
			}else
	{message_vision(HIG"�㻹û�дﵽ�ɾ���ȡҪ�󡢻������Ѿ���ȡ���ˡ�"NOR"\n", me);
	    return 1;}
		break;
	  case "��Ӱ����" :
			if(!me->query("titles/��Ӱ����")&&me->query_skill("kuihua-shengong")>=500&&me->query_skill("piaomiao-shenfa")>=500)
			{
			me->add("int",1);
			me->add("dex",1);
			me->add("con",1);
			me->add("str",1);
			me->add("max_qi",1000);
			me->set("titles/��Ӱ����",1);
//				me->set("zhanlinglq/s1",1);
				tell_object(me,"�ƺ���ȡ�ɹ���\n");
				return 1;
			}else
	{message_vision(HIG"�㻹û�дﵽ�ɾ���ȡҪ�󡢻������Ѿ���ȡ���ˡ�"NOR"\n", me);
	    return 1;}
		break;
	case "���ɵй�" :
			if(!me->query("titles/���ɵй�")&&me->query("yuanbao")>=9999999)
			{
			me->add("int",1);
			me->add("dex",1);
			me->add("con",1);
			me->add("str",1);
			me->add("max_qi",1000);
			me->set("titles/���ɵй�",1);
//				me->set("zhanlinglq/s1",1);
				tell_object(me,"�ƺ���ȡ�ɹ���\n");
				return 1;
			}else
	{message_vision(HIG"�㻹û�дﵽ�ɾ���ȡҪ�󡢻������Ѿ���ȡ���ˡ�"NOR"\n", me);
	    return 1;}
		break;
	case "������" :
			if(!me->query("titles/������")&&me->query("per")>=50&&me->query("gender") == "Ů��")
			{
			me->add("int",1);
			me->add("dex",1);
			me->add("con",1);
			me->add("str",1);
			me->add("max_qi",1000);
			me->set("titles/������",1);
//				me->set("zhanlinglq/s1",1);
				tell_object(me,"�ƺ���ȡ�ɹ���\n");
				return 1;
			}else
	{message_vision(HIG"�㻹û�дﵽ�ɾ���ȡҪ�󡢻������Ѿ���ȡ���ˡ�"NOR"\n", me);
	    return 1;}
		break;
			case "İ�Ͼ���" :
			if(!me->query("titles/İ�Ͼ���")&&me->query("per")>=50&&me->query("gender") == "����")
			{
			me->add("int",1);
			me->add("dex",1);
			me->add("con",1);
			me->add("str",1);
			me->add("max_qi",1000);
			me->set("titles/İ�Ͼ���",1);
//				me->set("zhanlinglq/s1",1);
				tell_object(me,"�ƺ���ȡ�ɹ���\n");
				return 1;
			}else
	{message_vision(HIG"�㻹û�дﵽ�ɾ���ȡҪ�󡢻������Ѿ���ȡ���ˡ�"NOR"\n", me);
	    return 1;}
		break;
					case "��������" :
			if(!me->query("titles/��������")&&me->query_skill("martial-cognize")>=500&&me->query_skill("sword-cognize")>=500)
			{
			me->add("int",1);
			me->add("dex",1);
			me->add("con",1);
			me->add("str",1);
			me->add("max_qi",1000);
			me->set("titles/��������",1);
//				me->set("zhanlinglq/s1",1);
				tell_object(me,"�ƺ���ȡ�ɹ���\n");
				return 1;
			}else
	{message_vision(HIG"�㻹û�дﵽ�ɾ���ȡҪ�󡢻������Ѿ���ȡ���ˡ�"NOR"\n", me);
	    return 1;}
		break;
					case "��������" :
			if(!me->query("titles/��������")&&me->query("age")>=100)
			{
			me->add("int",1);
			me->add("dex",1);
			me->add("con",1);
			me->add("str",1);
			me->add("max_qi",1000);
			me->set("titles/��������",1);
//				me->set("zhanlinglq/s1",1);
				tell_object(me,"�ƺ���ȡ�ɹ���\n");
				return 1;
			}else
	{message_vision(HIG"�㻹û�дﵽ�ɾ���ȡҪ�󡢻������Ѿ���ȡ���ˡ�"NOR"\n", me);
	    return 1;}
		break;
	  case "һ������" :
			if(!me->query("titles/һ������")&&me->query_skill("feixian-sword")>=500)
			{
			me->add("int",1);
			me->add("dex",1);
			me->add("con",1);
			me->add("str",1);
			me->add("max_qi",1000);
			me->set("titles/һ������",1);
//				me->set("zhanlinglq/s1",1);
				tell_object(me,"�ƺ���ȡ�ɹ���\n");
				return 1;
			}else
	{message_vision(HIG"�㻹û�дﵽ�ɾ���ȡҪ�󡢻������Ѿ���ȡ���ˡ�"NOR"\n", me);
	    return 1;}
		break;
	  default :
		message_vision(HIC "��ȡ��������ϵ��ʦ��\n" NOR,me);
	    return 1;
	}		
//              sscanf(arg, "%s ", a);


//        return 1;
	}



int help(object me)
{
     write(@HELP
ָ���ʽ: uplv [-s]

���ָ������������Ϊ�����ȼ���

HELP
    );
    return 1;
}
