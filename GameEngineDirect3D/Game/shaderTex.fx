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

sampler2D _MainTex : register(s0);
float num;

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
	FS_OUTPUT pixel;
	float4 color = tex2D(_MainTex, fragment.uv);
	float grayScale = (color.r + color.g + color.b) / 3;
	pixel.color = lerp(color, grayScale, sin(num));
	return pixel;

	/*FS_OUTPUT pixel;
	pixel.color = tex2D(_MainTex, fragment.uv);
	return pixel;*/
}

technique RedColor
{
	pass Pass0
	{
		VertexShader = compile vs_2_0 VS();
		PixelShader = compile ps_2_0 FS();
	}
}