ROM_START( galagab2 )
	ROM_REGION( 0x10000, REGION_CPU1, 0 )     /* 64k for code for the first CPU  */
	ROM_LOAD( "g1",           0x0000, 0x1000, CRC(ab036c9f) SHA1(ca7f5da42d4e76fd89bb0b35198a23c01462fbfe) )
	ROM_LOAD( "g2",           0x1000, 0x1000, CRC(d9232240) SHA1(ab202aa259c3d332ef13dfb8fc8580ce2a5a253d) )
	ROM_LOAD( "04j_g03.bin",  0x2000, 0x1000, CRC(753ce503) SHA1(481f443aea3ed3504ec2f3a6bfcf3cd47e2f8f81) )
	ROM_LOAD( "g4",           0x3000, 0x1000, CRC(499fcc76) SHA1(ddb8b121903646c320939c7d13f4aa4ebb130378) )

	ROM_REGION( 0x10000, REGION_CPU2, 0 )     /* 64k for the second CPU */
	ROM_LOAD( "04e_g05.bin",  0x0000, 0x1000, CRC(3102fccd) SHA1(d29b68d6aab3217fa2106b3507b9273ff3f927bf) )

	ROM_REGION( 0x10000, REGION_CPU3, 0 )     /* 64k for the third CPU  */
	ROM_LOAD( "04d_g06.bin",  0x0000, 0x1000, CRC(8995088d) SHA1(d6cb439de0718826d1a0363c9d77de8740b18ecf) )

	ROM_REGION( 0x10000, REGION_CPU4, 0 )	/* 64k for a Z80 which emulates the custom I/O chip (not used) */
	ROM_LOAD( "10h_g07.bin",  0x0000, 0x1000, CRC(035e300c) SHA1(cfda2467e71c27381b7150ff8fc7b69d61df123a) )

	ROM_REGION( 0x1000, REGION_GFX1, ROMREGION_DISPOSE )
	ROM_LOAD( "gallag.8",     0x0000, 0x1000, CRC(169a98a4) SHA1(edbeb11076061e744ea88d9899dbdfe0964c7e78) )

	ROM_REGION( 0x2000, REGION_GFX2, ROMREGION_DISPOSE )
	ROM_LOAD( "07e_g10.bin",  0x0000, 0x1000, CRC(ad447c80) SHA1(e697c180178cabd1d32483c5d8889a40633f7857) )
	ROM_LOAD( "07h_g09.bin",  0x1000, 0x1000, CRC(dd6f1afc) SHA1(c340ed8c25e0979629a9a1730edc762bd72d0cff) )

	ROM_REGION( 0x0320, REGION_PROMS, 0 )
	ROM_LOAD( "5n.bin",       0x0000, 0x0020, CRC(54603c6b) SHA1(1a6dea13b4af155d9cb5b999a75d4f1eb9c71346) )	/* palette */
	ROM_LOAD( "2n.bin",       0x0020, 0x0100, CRC(a547d33b) SHA1(7323084320bb61ae1530d916f5edd8835d4d2461) )	/* char lookup table */
	ROM_LOAD( "1c.bin",       0x0120, 0x0100, CRC(b6f585fb) SHA1(dd10147c4f05fede7ae6e7a760681700a660e87e) )	/* sprite lookup table */
	ROM_LOAD( "5c.bin",       0x0220, 0x0100, CRC(8bd565f6) SHA1(bedba65816abfc2ebeacac6ee335ca6f136e3e3d) )	/* unknown */
    
	ROM_REGION( 0x0100, REGION_SOUND1, 0 )	/* sound prom */
	ROM_LOAD( "1d.bin",       0x0000, 0x0100, CRC(86d92b24) SHA1(6bef9102b97c83025a2cf84e89d95f2d44c3d2ed) )
ROM_END

    ROM_LOAD( "prom-2.5c",    0x0100, 0x0100, CRC(77245b66) SHA1(0c4d0bee858b97632411c440bea6948a74759746) ) // unused

