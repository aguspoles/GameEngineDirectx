struct VS_INPUT
{
	float4 pos : POSITION;
	float2 uv : TEXCOORD;
};

struct VS_OUTPUT
{
	float4 pos : SV_POSITION;
	float4 posCopy : TEXCOORD2;
	float2 uv : TEXCOORD;
};

struct FS_OUTPUT
{
	float4 color : COLOR;
};

VS_OUTPUT VS(VS_INPUT vertex)
{
	VS_OUTPUT fragment;

	fragment.pos = vertex.pos;
	fragment.pos.xyz *= 0.5;
	fragment.pos.xy  -= 0.25;

	fragment.posCopy = fragment.pos;
	fragment.uv = vertex.uv;

	return fragment;
}

FS_OUTPUT FS(VS_OUTPUT fragment)
{
	//Efecto minerva
	//clip(frac(fragment.posCopy.y * 10) - 0.5);

	FS_OUTPUT pixel;
	pixel.color = float4(fragment.posCopy.x, fragment.posCopy.y, fragment.posCopy.z, 0);
	pixel.color *= 5;
	return pixel;
}

technique RedColor
{
	pass Pass0
	{
		VertexShader = compile vs_2_0 VS();
		PixelShader = compile ps_2_0 FS();
	}
}