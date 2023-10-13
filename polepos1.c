/********************************************************************
ROM_START( polepos1 )
	/* Z80 memory/ROM data */
	ROM_REGION( 0x10000, REGION_CPU1, 0 )
	ROM_LOAD	 ( "014-105.rom",   0x0000, 0x2000, CRC(c918c043) SHA1(abc1aa3d7b670b5a65b4565dc646cd3c4edf4e6f) )
	ROM_LOAD	 ( "014-116.rom",   0x2000, 0x1000, CRC(7174bcb7) SHA1(460326a6cea201db2df813013c95562a222ea95d) )

	/* Z8002 #1 memory/ROM data */
	ROM_REGION( 0x10000, REGION_CPU2, 0 )
	ROM_LOAD16_BYTE( "014-101.rom",   0x0001, 0x2000, CRC(8c2cf172) SHA1(57c774afab79599ac3f434113c3170fbb3d42620) )
	ROM_LOAD16_BYTE( "014-102.rom",   0x0000, 0x2000, CRC(51018857) SHA1(ed28d44d172a01f76461f556229d1fe3a1b779a7) )

	/* Z8002 #2 memory/ROM data */
	ROM_REGION( 0x10000, REGION_CPU3, 0 )
	ROM_LOAD16_BYTE( "103.3e",        0x0001, 0x2000, CRC(af4fc019) SHA1(1bb6c0f3ffada2e1df72e1767581f8e8bb2b18f9) )
	ROM_LOAD16_BYTE( "104.4e",        0x0000, 0x2000, CRC(ba0045f3) SHA1(aedb8d8c56407963aa4ffb66243288c8fd6d845a) )

	/* graphics data */
	ROM_REGION( 0x02000, REGION_GFX1, ROMREGION_DISPOSE ) 	/* 2bpp alpha layer */
	ROM_LOAD	 ( "014-132.rom",   0x0000, 0x1000, CRC(a949aa85) SHA1(2d6414196b6071101001128418233e585279ffb9) )

	ROM_REGION( 0x02000, REGION_GFX2, ROMREGION_DISPOSE ) 	/* 2bpp view layer */
	ROM_LOAD	 ( "014-133.rom",   0x0000, 0x1000, CRC(3f0eb551) SHA1(39516d0f72f4e3b03df9451d2dbe081d6c71a508) )

	ROM_REGION( 0x04000, REGION_GFX3, ROMREGION_DISPOSE ) 	/* 4bpp 16x16 sprites */
	ROM_LOAD	 ( "014-156.rom",   0x0000, 0x2000, CRC(e7a09c93) SHA1(47cc5c6776333bba8454a3df9e2f6e7de4a465e1) )    /* 4bpp sm sprites, planes 0+1 */
	ROM_LOAD	 ( "014-157.rom",   0x2000, 0x2000, CRC(dee7d687) SHA1(ea34b51c91f6915b74a4a7b53ddb4ff36b72bf66) )    /* 4bpp sm sprites, planes 2+3 */

	ROM_REGION( 0x10000, REGION_GFX4, ROMREGION_DISPOSE ) 	/* 4bpp 32x32 sprites */
	ROM_LOAD	 ( "014-150.rom",   0x0000, 0x2000, CRC(2e134b46) SHA1(0938f5f9f5cc6d7c1096c569449db78dbc42da01) )    /* 4bpp lg sprites, planes 0+1 */
	ROM_LOAD	 ( "014-152.rom",   0x2000, 0x2000, CRC(a7e3a1c6) SHA1(b7340318afaa4b5f416fe4444899579242cd36c2) )
	ROM_LOAD	 ( "014-154.rom",   0x4000, 0x2000, CRC(8992d381) SHA1(3bf2544dbe88132137acec2c064a104a74139ec7) )
	ROM_LOAD	 ( "014-151.rom",   0x8000, 0x2000, CRC(6f9997d2) SHA1(b26d505266ccf23bfd867f881756c3251c80f57b) )    /* 4bpp lg sprites, planes 2+3 */
	ROM_LOAD	 ( "014-153.rom",   0xa000, 0x2000, CRC(6c5c6e68) SHA1(dce74ee0e69e0fc0a1942a489c2065381239f0f1) )
	ROM_LOAD	 ( "014-155.rom",   0xc000, 0x2000, CRC(111896ad) SHA1(15032b4c859231373bebfa640421fdcc8ba9d211) )

	/* graphics (P)ROM data */
	ROM_REGION( 0x7000, REGION_PROMS, 0 )
	ROM_LOAD	 ( "014-137.bpr",   0x0000, 0x0100, CRC(f07ff2ad) SHA1(e1f3cb10a03d23f8c1d422acf271dba4e7b98cb1) )    /* red palette PROM */
	ROM_LOAD	 ( "014-138.bpr",   0x0100, 0x0100, CRC(adbde7d7) SHA1(956ac5117c1e310f554ac705aa2dc24a796c36a5) )    /* green palette PROM */
	ROM_LOAD	 ( "014-139.bpr",   0x0200, 0x0100, CRC(ddac786a) SHA1(d1860105bf91297533ccc4aa6775987df198d0fa) )    /* blue palette PROM */
	ROM_LOAD	 ( "014-140.bpr",   0x0300, 0x0100, CRC(1e8d0491) SHA1(e8bf1db5c1fb04a35763099965cf5c588240bde5) )    /* alpha color PROM */
	ROM_LOAD	 ( "014-141.bpr",   0x0400, 0x0100, CRC(0e4fe8a0) SHA1(d330b1e5ebccf5bbefcf71486fd80d816de38196) )    /* view color PROM */
	ROM_LOAD	 ( "014-142.bpr",   0x0500, 0x0100, CRC(2d502464) SHA1(682b7dd22e51d5db52c0804b7e27e47641dfa6bd) )    /* vertical position low PROM */
	ROM_LOAD	 ( "014-143.bpr",   0x0600, 0x0100, CRC(027aa62c) SHA1(c7030d8b64b80e107c446f6fbdd63f560c0a91c0) )    /* vertical position med PROM */
	ROM_LOAD	 ( "014-144.bpr",   0x0700, 0x0100, CRC(1f8d0df3) SHA1(b8f17758f114f5e247b65b3f2922ca2660757e66) )    /* vertical position hi PROM */
	ROM_LOAD	 ( "014-145.bpr",   0x0800, 0x0400, CRC(7afc7cfc) SHA1(ba2407f6eff124e881b354f13205a4c058b7cf60) )    /* road color PROM */
	ROM_LOAD	 ( "014-146.bpr",   0x0c00, 0x0400, CRC(ca4ba741) SHA1(de93d738bd27e24dbc4a8378d2c120ef8388c261) )    /* sprite color PROM */
	ROM_LOAD	 ( "131.11n",       0x1000, 0x1000, CRC(5921777f) SHA1(4d9c91a26e0d84fbbe08f748d6e0364311ed6f73) )    /* vertical scaling PROM */
	ROM_LOAD	 ( "014-158.rom",   0x2000, 0x2000, CRC(ee6b3315) SHA1(9cc26c6d3604c0f60d716f86e67e9d9c0487f87d) )    /* road control PROM */
	ROM_LOAD	 ( "014-159.rom",   0x4000, 0x2000, CRC(6d1e7042) SHA1(90113ff0c93ed86d95067290088705bb5e6608d1) )    /* road bits 1 PROM */
	ROM_LOAD	 ( "014-134.rom",   0x6000, 0x1000, CRC(4e97f101) SHA1(f377d053821c74aee93ebcd30a4d43e6156f3cfe) )    /* read bits 2 PROM */

	/* sound (P)ROM data */
	ROM_REGION( 0xd000, REGION_SOUND1, 0 )
	ROM_LOAD	 ( "014-118.bpr",   0x0000, 0x0100, CRC(8568decc) SHA1(0aac1fa082858d4d201e21511c609a989f9a1535) )    /* Namco sound PROM */
	ROM_LOAD	 ( "014-110.rom",   0x1000, 0x2000, CRC(b5ad4d5f) SHA1(c07e77a050200d6fe9952031f971ca35f4d15ff8) )    /* engine sound PROM */
	ROM_LOAD	 ( "014-111.rom",   0x3000, 0x2000, CRC(8fdd2f6f) SHA1(3818dc94c60cd78c4212ab7a4367cf3d98166ee6) )    /* engine sound PROM */
	ROM_LOAD	 ( "014-106.rom",   0x5000, 0x2000, CRC(5b4cf05e) SHA1(52342572940489175607bbf5b6cfd05ee9b0f004) )    /* voice PROM */

	/* unknown or unused (P)ROM data */
	ROM_REGION( 0x0100, REGION_USER1, 0 )
	ROM_LOAD	 ( "014-117.bpr",   0x0000, 0x0100, CRC(2401c817) SHA1(8991b7994513a469e64392fa8f233af5e5f06d54) )    /* sync chain */
ROM_END
