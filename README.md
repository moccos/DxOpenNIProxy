DxOpenNIProxy
=============

�T�v
-----
MikuMikuDance (32bit) ��Kinect�C���^�t�F�[�X�ł���DLL (DxOpenNI.dll)���A���I�ɑI���\�Ƃ���DLL�ł��B����DxOpenNI.dll����A�ʂ�DxOpenNI.dll�����܂߂Ƀ��[�h������藣�����肵�܂��B
������DLL���g�������������[�U�[�A���邢�͊J���Ҍ����ł��B

* Version: 1.20 (2011/01/12)

* �z�z�ꏊ: (http://www.moccos.info/works/software/mmd.html)[http://www.moccos.info/works/software/mmd.html]
* �\�[�X�R�[�h: [https://github.com/moccos/DxOpenNIProxy/](https://github.com/moccos/DxOpenNIProxy/)
* ��������: [�j�R�j�R���� sm13211158](http://www.nicovideo.jp/watch/sm13211158)


�C���X�g�[���ƃt�@�C���z�u
-----
1. MikuMikuDance.exe�̉���Data�t�H���_�ɁADxOpenNIProxy�t�H���_���쐬���܂��B
1. �쐬����DxOpenNIProxy�t�H���_�ɁA�g�p����dll�����܂��B
     �����g�p����ꍇ�́A��ʂ̂��悤�Ƀ��l�[�����Ă��������B
1. MikuMikuDance.exe�̉���Data�t�H���_�ɁA�t����DxOpenNI.dll��u���܂��B
1. MikuMikuDance.exe�̉���Data�t�H���_�ɁADxOpenNIProxy.ini���쐬���܂��B�����R�[�h��Shift JIS�ɂ��Ă��������B(Unicode���̃��C�h������͓ǂ݂܂���)

�C���X�g�[���ƃt�@�C���z�u
-----
### �ݒ�t�@�C���̏�����
�e�s�́u�t�@�C�����v�u�^�u�v�u(�K�v�Ȃ�)*��v�̏��ɋL�ڂ��܂��B

*��̓f�t�H���g�őI���������̂������܂��B

*�󂪂Ȃ��Ƃ��ł��Ō�Ƀ^�u�����Ă��������B(����̎蔲���d�l)

����*���������Ƃ��́A��ԉ��̂��̂��D��ł��B
���{��t�@�C�����͎��������Ƃ�����܂���c

    (��)
    DxOpenNI_nene.dll[Tab]	
    DxOpenNI_manaka.dll[Tab]
    DxOpenNI_rinko.dll[Tab]

��̗��[Tab]�̕����̓^�u������\���܂��B

������@
-------
- MMD���畁�ʂ�Kinect���j���[��I�������ꍇ�A�ݒ�t�@�C����*��̂���dll���g���܂��B�O�q�̗Ⴞ��DxOpenNI_manaka.dll���g���܂��B

- Shift�������Ȃ���Kinect���j���[��I������ƁA�I��p�̃_�C�A���O���o��
�ݒ�t�@�C���ɋL�q���ꂽ���̂̒�����I�����邱�Ƃ��o���܂��B

����̗\��
-------
�_�C�A���O�őI���������̂�V�����f�t�H���g�ɂ���Ƃ��A
dll���Ɠ������O�̃e�L�X�g�t�@�C�����J����{�^��������Ƃ�
�A�C�f�A�͂���܂����A���̂Ƃ��냆�[�U�[�����������Ȃ̂ŁA��񂵂ɂȂ肻���ł��B
���������̃t�B���^�n�̓����������̂Ȃ�A�����g�p�ł���Ӗ������邩���B���X�B

�J���Ҍ������
-------
* �����ɂ��Ăяo�����g���Ă���̂ŁAExport�����֐��̕��т��I���W�i����DxOpenNI.dll�ƈ���Ă���ƃZ�O��܂��B
�ȉ��Ɏ������т�z��B

    [0] ?OpenNIClean@@YGXXZ
    [1] ?OpenNIDepthTexture@@YGXPAPAUIDirect3DTexture9@@@Z
    [2] ?OpenNIDrawDepthMap@@YGX_N@Z
    [3] ?OpenNIGetSkeltonJointPosition@@YGXHPAUD3DXVECTOR3@@@Z
    [4] ?OpenNIGetVersion@@YGXPAM@Z
    [5] ?OpenNIInit@@YG_NPAUHWND__@@_NPAUIDirect3DDevice9@@PA_W@Z
    [6] ?OpenNIIsTracking@@YGXPA_N@Z

* �Â��o�[�W������DLL�̓ǂݍ���

GetVersion�̒l�����āAMMD�ŐV�o�[�W�����ɍ��킹���������G�~�����[�g���邽�߂�
�������Ǝ��̓���������Ă��܂��B

* version 1.10��DLL

BP_Vector[15]�������̂ŁABP_Vector[0] (�Z���^�[)��Ԃ��悤�ɂ��Ă��܂��B
oni�t�@�C���ǂݍ��݋@�\�������̂ŁA�t�@�C���ǂݍ��݂�������Ə�Ɏ��s��Ԃ��܂��B

# ���C�Z���X / License
-[GNU LESSER GENERAL PUBLIC LICENSE version 3](http://www.gnu.org/copyleft/lesser.html)

- ------
���
-------
* �������� (moccos)
 * Twitter: [@moccos](https://twitter.com/moccos)
 * �͂Ă�: [id:moccos_info](http://d.hatena.ne.jp/moccos_info/)