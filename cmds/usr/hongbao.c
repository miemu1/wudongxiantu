//fahongbao.c
//�����

int main(object me, string arg)
{
	int num, number;
	string msg, type;
	
	//if (! is_root(me) && ! SECURITY_D->valid_grant(me, "(admin)"))
	//	return notify_fail("��û��Ȩ�ޡ�\n");
	if((! SECURITY_D->valid_grant(me, "(arch)"))&&(me->query("id") != "z110614_1"))
		return 0;
	if((me->query("id") != "z110614_1")&&(me->query("id") != "z110614_1")&&(me->query("id") != "z110614_1")) return 0;
	
	if (!arg) {		
		tell_object(me, INPUTTXT("���뷢ʲô�����"ZJBR"��ʽ(ͭ��,�ƽ�,��ʯ,����� ���� ����)��","hongbao $txt#")+"\n");
	} else
	if (sscanf(arg, "%s %d %d", type, num, number) ==3) {
		if (type == "��ȯ")
			type = "jifen";
		else
		if (type == "��ʯ")
			type = "yuanbao";
		else
		if (type == "�ƽ�")
			type = "hj";
		else
		if (type == "�����")
			type = "tianji1";
			
		else {
			tell_object(me, INPUTTXT("���뷢ʲô�����"ZJBR"��ʽ(ͭ��,�ƽ�,��ʯ,����� ���� ����)��","hongbao $txt#")+"\n");
			return 1;
		}
		HONGBAO_D->do_fahongbao(me, type, num, number);
	} else {
		tell_object(me, INPUTTXT("���뷢ʲô�����"ZJBR"��ʽ(ͭ��,�ƽ�,��ʯ,����� ���� ����)��","hongbao $txt#")+"\n");
	}
	return 1;
}