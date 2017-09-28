struct VS_INPUT
{
	float4 pos : POSITION;
	float3 normal : NORMAL;
	float2 uv : TEXCOORD;
};

struct VS_OUTPUT
{
	float4 pos : SV_POSITION;
	float2 uv : TEXCOORD;
};

struct FS_OUTPUT
{
	float4 color : COLOR; 
};

//sampler2D _MainTex : register(s0);
float4x4 texMatrix;
texture tex;
float4 _Color;
float4x4 mvp;
sampler2D _MainTex = sampler_state
{
	texture = tex;
	MagFilter = LINEAR;
};
float num;

VS_OUTPUT VS(VS_INPUT vertex)
{
	VS_OUTPUT fragment;
	fragment.pos = mul(vertex.pos, mvp);
	float4 temp = mul(float4(vertex.uv.x, vertex.uv.y, 1.0f, 1.0f), texMatrix);
	fragment.uv = temp.xy;
	return fragment;
}

FS_OUTPUT FS(VS_OUTPUT fragment)
{
	FS_OUTPUT pixel;
	pixel.color = tex2D(_MainTex, fragment.uv) * _Color * num * 2;
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
